// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "BoardManager.h"
#include "InteractionManager.h"
#include "utils.h"

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
    displayBoard(cadre, dims);
    char in;
    int curr_y = cadre.origw + 2, curr_x = cadre.origh;
    gotoxy(curr_x, curr_y);
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
                cout << "Sure to quit? (Y/n)" << endl;
                do {
                    cin >> in;
                    if (userConfirmed(in)) {
                        return 0;
                    }
                    else if (userIsNotSure(in)) {
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
