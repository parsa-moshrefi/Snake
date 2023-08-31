#ifndef BOARD_MANAGER
#define BOARD_MANAGER

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <utility>
#include <list>
#include <windows.h>
using namespace std;

#include <random>
#include "utils.h"

int getObstacleCount(int width, int height) {
    return (int)(OBSTACLE_PERCENT * width * height);
}

int getFeedCount(int width, int height) {
    return (int)(FEED_PERCENT * width * height);
}

void clearBoard() {
	system("cls");
}

void initializeBoard(CADRE* cadre, DIMENSIONS* dims) {
    cadre->board = new char* [dims->width];

    for (int i = 0; i < dims->width; i++) {
        cadre->board[i] = new char[dims->height];
    }

    for (int i = 0; i < dims->width; i++) {
        for (int j = 0; j < dims->height; j++)
        {
            cadre->board[i][j] = EMPTY;
        }
    }
}


void fillObstacles(CADRE* cadre, DIMENSIONS* dims) {
    random_device rd;
    mt19937 rng(rd());
    int obstacleCount = getObstacleCount(dims->width, dims->height);
    uniform_int_distribution<int> rndwIdx(1, dims->width - 1), rndhIdx(1, dims->height - 1);
    for (int r = 0; r < obstacleCount; r++) {
        int i = rndwIdx(rng), j = rndhIdx(rng);
        cadre->board[i][j] = OBSTACLE;
    }
}


void fillFeeds(CADRE* cadre, DIMENSIONS* dims) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> rndwIdx(1, dims->width - 1), rndhIdx(1, dims->height - 1);
    int feedCount = getFeedCount(dims->width, dims->height);

    for (int f = 0; f < feedCount; f++) {
        int i, j;
        do {
            i = rndwIdx(rng), j = rndhIdx(rng);
        } while (cadre->board[i][j] == OBSTACLE);

        cadre->board[i][j] = FEED;
    }
}

void placeSnakeOrigin(CADRE* cadre, DIMENSIONS* dims, list<pair<int, int>>* snake) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> rndwIdx(1, dims->width - 1), rndhIdx(1, dims->height - 1);

    int origw, origh;
    do {
        origw = rndwIdx(rng), origh = rndhIdx(rng);
    } while (cadre->board[origw][origh] != EMPTY);

    cadre->board[origw][origh] = SNAKE;
    cadre->origh = origh;
    cadre->origw = origw;
	pair<int, int> origin;
	origin.first = origw;
	origin.second = origh;
	snake->push_front(origin);
}

DIMENSIONS promptDimensions() {
    DIMENSIONS dimensions;
    cout << "width: ";
    cin >> dimensions.width;
    cout << "height: ";
    cin >> dimensions.height;
    return dimensions;
}

void displayBoard(CADRE cadre, DIMENSIONS dims, pair<int, int>* loc, list<pair<int, int>>* snake) {	

	clearBoard();
	
	for (int h = 0; h < dims.height + 2; h++)
		cout << OBSTACLE;
		
	gotoxy(0, dims.width + 1);
	
	for (int h = 0; h < dims.height + 2; h++)
		cout << OBSTACLE;
	
	for (int w = 1; w < dims.width + 2; w++) {
		gotoxy(0, w);
		cout << OBSTACLE;
	}
		
	for (int w = 1; w < dims.width + 2; w++) {
		gotoxy(dims.height + 1, w);
		cout << OBSTACLE;
	}
	
    for (int w = 0; w < dims.width; w++) {
        for (int h = 0; h < dims.height; h++) {
        	gotoxy(h+1, w+1);
            cout << cadre.board[w][h];
        }
    }
    
    loc->first = cadre.origw + 1;
    loc->second = cadre.origh + 1;
	gotoxy(loc->second, loc->first);
}

void maximizeConsole() {
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}

bool onBorders(pair<int, int> room, Dimensions* dims) {
	
	if (dims == NULL) {
		return false;
	}
	
	return (room.first == 0 || 
			room.first == dims->width || 
			room.second == 0 || 
			room.second == dims->height);
}

#endif