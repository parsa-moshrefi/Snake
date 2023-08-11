#ifndef BOARD_INITIALIZER
#define BOARD_INITIALIZER

#define EMPTY ' '
#define OBSTACLE 'O'
#define FEED 'F'
#define SNAKE 'S'
#define OBSTACLE_PERCENT 0.01
#define FEED_PERCENT 0.005

#include <iostream>
#include <conio.h>
#include <stdlib.h>
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

void placeSnakeOrigin(CADRE* cadre, DIMENSIONS* dims) {
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
}

DIMENSIONS promptDimensions() {
    DIMENSIONS dimensions;
    cout << "width: ";
    cin >> dimensions.width;
    cout << "height: ";
    cin >> dimensions.height;
    return dimensions;
}

void displayBoard(CADRE cadre, DIMENSIONS dims, LOCATION* loc) {
	system("cls");
    for (int w = 0; w < dims.width; w++) {
        for (int h = 0; h < dims.height; h++) {
            cout << cadre.board[w][h];
        }
        cout << endl;
    }
    loc->h = cadre.origw;
    loc->w = cadre.origh;
	gotoxy(loc->w, loc->h);
}

#endif