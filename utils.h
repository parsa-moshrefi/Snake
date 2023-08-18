#ifndef UTILS
#define UTILS
#include <windows.h>

typedef struct Dimensions {
    int width;
    int height;
} DIMENSIONS;

typedef struct Board {
    int origw;
    int origh;
    char** board;
} CADRE;

typedef struct Location {
	int w;
	int h;
} LOCATION;

void gotoxy(short a, short b) {
	COORD coordinates;
	coordinates.X = a;
	coordinates.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void delay(int dly) {
	for (int i=0; i<dly; i++);
}

#endif