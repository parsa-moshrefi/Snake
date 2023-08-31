#ifndef UTILS
#define UTILS
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <thread>
using namespace std::chrono_literals;
#define KEY_STROKE 1
#define GROWTH 2
#define WONE 3
#define LOUSED 4
#define UNKNOWN 5
#define EMPTY ' '
#define OBSTACLE '#'
#define FEED '$'
#define SNAKE '*'
#define OBSTACLE_PERCENT 0.01
#define FEED_PERCENT 0.05


typedef struct Dimensions {
    int width;
    int height;
} DIMENSIONS;

typedef struct Board {
    int origw;
    int origh;
    char** board;
} CADRE;

void gotoxy(short a, short b) {
	COORD coordinates;
	coordinates.X = a;
	coordinates.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int delay() {
	std::this_thread::sleep_for(500ms);
	if (kbhit()) {
		return KEY_STROKE;
	}

	return 0;
}

#endif