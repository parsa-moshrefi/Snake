// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "BoardManager.h"
#include "InteractionManager.h"

#include <conio.h>
#include <stdio.h>
#include <utility>
#include <list>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75


CADRE initializeCadre(DIMENSIONS dims, list<pair<int, int>>* snake) {
    CADRE cadre;
    maximizeConsole();
    // initialize the plate by pointer
    initializeBoard(&cadre, &dims);
    fillObstacles(&cadre, &dims);
    fillFeeds(&cadre, &dims);
    placeSnakeOrigin(&cadre, &dims, snake);
    return cadre;
}


int startGame() {
	list<pair<int, int>> snake;
    DIMENSIONS dims = promptDimensions();
    CADRE cadre = initializeCadre(dims, &snake);
    LOCATION loc;
    displayBoard(cadre, dims, &loc, &snake);
    char in;
    do {
        in = (char) _getch();
        switch (in) {
            case UP:
                cout << "Up pressed" << endl;
                break;
            case DOWN:
                cout << "Down pressed" << endl;
                break;
            case LEFT:
                cout << "Left pressed" << endl;
                break;
            case RIGHT:
                cout << "Right pressed" << endl;
                break;
            case EXIT:
            case (char)(EXIT + LETTER_NUMBER):
				if (confirmExit(loc, dims.width + 2)) {
					return 0;
				}
        }
    } while (true);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    return startGame();
}
