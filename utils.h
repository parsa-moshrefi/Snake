#include <windows.h>


void gotoxy(short a, short b) {
	COORD coordinates;
	coordinates.X = a;
	coordinates.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

