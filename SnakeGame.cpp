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
#define KEY_STROKE 1


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
    pair<int, int> loc;
    displayBoard(cadre, dims, &loc, &snake);
    int result = 0;
    char in, prevIn;
    do {
        in = (char) _getch();
        switch (in) {
            case UP:
				if (prevIn != DOWN) {
					result = goUp(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}
					}
					prevIn = UP;
				} else {
					result = goDown(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}
					}
				}
                break;
            case DOWN:
                if (prevIn != UP) {
                	result = goDown(&snake, &cadre, &dims);
                	if (result == WONE || result == LOUSED) {
                		if (logByResult(result, &dims) == 0) {
                			return 0;
						}
					}
					prevIn = DOWN;
				} else {
					result = goUp(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}
					}
				}
                break;
            case LEFT:
            	if (prevIn != RIGHT) {
            		result = goLeft(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}
					}
					prevIn = LEFT;
				} else {
	                result = goRight(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}						
					}
				}
                break;
            case RIGHT:
            	if (prevIn != LEFT) {
            		result = goRight(&snake, &cadre, &dims);
            		if (result == WONE || result == LOUSED) {
            			if (logByResult(result, &dims) == 0) {
            				return 0;
						}
					}
					prevIn = RIGHT;
				} else {
	                result = goLeft(&snake, &cadre, &dims);
					if (result == WONE || result == LOUSED) {
						if (logByResult(result, &dims) == 0) {
							return 0;
						}						
					}
				}
				break;
            case EXIT:
            case (char)(EXIT + LETTER_NUMBER):
				if (confirmExit(loc, dims.width + 2)) {
					return 0;
				}
			default:
				if (result == KEY_STROKE) {
					continue;
				}
        }
    } while (true);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    return startGame();
}
