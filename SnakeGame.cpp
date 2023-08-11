// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "BoardManager.h"
#include "InteractionManager.h"

#include <conio.h>
#include <stdio.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75



CADRE initializeCadre(DIMENSIONS dims) {
    CADRE cadre;

    // initialize the plate by pointer
    initializeBoard(&cadre, &dims);
    fillObstacles(&cadre, &dims);
    fillFeeds(&cadre, &dims);
    placeSnakeOrigin(&cadre, &dims);
    return cadre;
}


int startGame() {
    DIMENSIONS dims = promptDimensions();
    CADRE cadre = initializeCadre(dims);
    LOCATION loc;
    displayBoard(cadre, dims, &loc);
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
            	gotoxy(0, dims.width + 1);
                cout << "Sure to quit? (Y/n)" << endl;
                do {
                    cin >> in;
                    if (userConfirmed(in)) {                    	
                        return 0;
                    }
                    else if (userIsNotSure(in)) {
                        gotoxy(loc.w, loc.w);
						break;
                    }
                    else {
                        cout << "invalid input. Try again (Y/n)." << endl;
                    }
                } while (!isUserContinuationCharacter(in));
        }
    } while (true);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    return startGame();
}
