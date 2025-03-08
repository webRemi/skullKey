#ifndef KEYMAP_H
#define KEYMAP_H

#include <Windows.h>

typedef struct {
	int VKCODE;
	char* value;
} keyMap;

keyMap keyMaps[] = {
	// CONTROL KEYS
	{ VK_BACK, "[BACK]" },
	{ VK_TAB, "[TAB]" },
	{ VK_CLEAR, "[CLEAR]" },
	{ VK_RETURN, "[ENTER]" },
	{ VK_SHIFT, "[SHIFT]" },
	{ VK_CONTROL, "[CTRL]" },
	{ VK_MENU, "[ALT]" },
	{ VK_PAUSE, "[PAUSE]" },
	{ VK_CAPITAL, "[CAPSLOCK]" },
	{ VK_ESCAPE, "[ESC]" },
	{ VK_SPACE, "[SPACE]" },
	{ VK_PRIOR, "[PAGEUP]" },
	{ VK_NEXT, "[PAGEDOWN]" },
	{ VK_LEFT, "[LARROW]" },
	{ VK_UP, "[UARROW" },
	{ VK_RIGHT, "[RARROW]" },
	{ VK_DOWN, "[DARROW]" },
	{ VK_SELECT, "[SELECT]" },
	{ VK_LSHIFT, "[LSHIFT]" },
	{ VK_RSHIFT, "[RSHIFT]" },

	// SPECIAL KEYS
	{ VK_OEM_PLUS, "+", },
	{ VK_OEM_COMMA, "," },
	{ VK_OEM_MINUS, "-" },
	{ VK_OEM_PERIOD, "." },
	{ VK_OEM_1, ";" },
	{ VK_OEM_2, "/" },
	{ VK_OEM_3, "`" },
	{ VK_OEM_4, "[" },
	{ VK_OEM_5, "\\" },
	{ VK_OEM_6, "]" },
	{ VK_OEM_7, "'"},

	// NUMBER KEYS
	{ 48, "0" },
	{ 49, "1" },
	{ 50, "2" },
	{ 51, "3" },
	{ 52, "4" },
	{ 53, "5" },
	{ 54, "6" },
	{ 55, "7" },
	{ 56, "8" },
	{ 57, "9" },

	// LETTER KEYS
	{ 65, "a" },
	{ 66, "b" },
	{ 67, "c" },
	{ 68, "d" },
	{ 69, "e" },
	{ 70, "f" },
	{ 71, "g" },
	{ 72, "h" },
	{ 73, "i" },
	{ 74, "j" },
	{ 75, "k" },
	{ 76, "l" },
	{ 77, "m" },
	{ 78, "n" },
	{ 79, "o" },
	{ 80, "p" },
	{ 81, "q" },
	{ 82, "r" },
	{ 83, "s" },
	{ 84, "t" },
	{ 85, "u" },
	{ 86, "v" },
	{ 87, "w" },
	{ 88, "x" },
	{ 89, "y" },
	{ 90, "z" },

	// F KEYS
	{ VK_F1, "[F1]" },
	{ VK_F2, "[F2]" },
	{ VK_F3, "[F3]" },
	{ VK_F4, "[F4]" },
	{ VK_F5, "[F5]" },
	{ VK_F6, "[F6]" },
	{ VK_F7, "[F7]" },
	{ VK_F8, "[F8]" },
	{ VK_F9, "[F9]" },
	{ VK_F10, "[F10]" },
	{ VK_F11, "[F11]" },
	{ VK_F12, "[F12]" },
	{ VK_F13, "[F13]" },
	{ VK_F14, "[F14]" },
	{ VK_F15, "[F15]" },
	{ VK_F16, "[F16]" },
	{ VK_F17, "[F17]" },
	{ VK_F18, "[F18]" },
	{ VK_F19, "[F19]" },
	{ VK_F20, "[F20]" },
	{ VK_F21, "[F21]" },
	{ VK_F22, "[F22]" },
	{ VK_F23, "[F23]" },
	{ VK_F24, "[F24]" },
};

#endif