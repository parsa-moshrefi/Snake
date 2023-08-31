#ifndef INTERACTION_MANAGER
#define INTERACTION_MANAGER

#define EXIT 'X'
#define LETTER_NUMBER 32
#define CONFIRM 'Y'
#define NOT_SURE 'N'
#define CARRIAGE_RETURN '\n'
#define KEY_STROKE 1
#include "Snake.h"


bool userConfirmed(char c) {
    return c == CONFIRM || c == (char)(CONFIRM + LETTER_NUMBER) || c == CARRIAGE_RETURN;
}

bool userIsNotSure(char c) {
    return c == NOT_SURE || c == (char)(NOT_SURE + LETTER_NUMBER);
}

bool isUserContinuationCharacter(char c) {
    return c == CONFIRM ||
        c == (char)(CONFIRM + LETTER_NUMBER) ||
        c == EXIT ||
        c == (char)(EXIT + LETTER_NUMBER);
}

bool confirmExit(pair<int, int> loc, int promptLine) {
	gotoxy(0, promptLine);
	char in;
    cout << "Sure to quit? (Y/n)                     " << endl;
    do {
        cin >> in;
        if (userConfirmed(in)) {                    	
            return true;
        }
        else if (userIsNotSure(in)) {
            gotoxy(loc.second, loc.first);
			break;
        }
        else {
        	gotoxy(0, promptLine);
        	printf("invalid input. Try again (Y/n).\n");
        }
    } while (!isUserContinuationCharacter(in));
    
    return false;
}

void printMessage(int promptLine, char* message) {
	gotoxy(0, promptLine);
	printf("%s\t\t\t", message);
}

int logByResult(int state, DIMENSIONS* dims) {
	char* woneMsg = "You wone!";
	char* lousedMsg = "You loused!";

	if (state == WONE) {
		printMessage(dims->width+2, woneMsg);
		return 0;
	} else if (state == LOUSED) {
		printMessage(dims->width+2, lousedMsg);
		return 0;
	}
	
	return UNKNOWN;
}

int goRight(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	int strokeResult = 0;
	int rightResult = 0;
	do {
		rightResult = moveRight(snake, cadre, dims);
		strokeResult = delay();
		if (strokeResult == KEY_STROKE) {
			return KEY_STROKE;
		}		
	} while (rightResult != WONE && rightResult != LOUSED);
	
	return rightResult;
}

int goLeft(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	int strokeResult = 0;
	int leftResult = 0;
	do {
		leftResult = moveLeft(snake, cadre, dims);
		strokeResult = delay();
		if (strokeResult == KEY_STROKE) {
			return KEY_STROKE;
		}
	} while (leftResult != WONE && leftResult != LOUSED);
	
	return leftResult;
}

int goUp(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	int strokeResult = 0;
	int upResult = 0;
	do {
		upResult = moveUp(snake, cadre, dims);
		strokeResult = delay();
		if (strokeResult == KEY_STROKE) {
			return KEY_STROKE;
		}
	} while (upResult != WONE && upResult != LOUSED);
	
	return upResult;
}

int goDown(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	int strokeResult = 0;
	int downResult = 0;
	do {
		downResult = moveDown(snake, cadre, dims);
		strokeResult = delay();
		if (strokeResult == KEY_STROKE) {
			return KEY_STROKE;
		}
	} while (downResult != WONE && downResult != LOUSED);
	
	return downResult;
}

#endif
