#ifndef INTERACTION_MANAGER
#define INTERACTION_MANAGER

#define EXIT 'X'
#define LETTER_NUMBER 32
#define CONFIRM 'Y'
#define NOT_SURE 'N'
#define CARRIAGE_RETURN '\n'
#define DELAY 200
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

bool confirmExit(LOCATION loc, int promptLine) {
	gotoxy(0, promptLine);
	char in;
    cout << "Sure to quit? (Y/n)                     " << endl;
    do {
        cin >> in;
        if (userConfirmed(in)) {                    	
            return true;
        }
        else if (userIsNotSure(in)) {
            gotoxy(loc.w, loc.h);
			break;
        }
        else {
        	gotoxy(0, promptLine);
        	printf("invalid input. Try again (Y/n).\n");
        }
    } while (!isUserContinuationCharacter(in));
    
    return false;
}

void goRight(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	// todo: why the following method is not defined in the scope
	// moveRight(snake, cadre, dims);
}

#endif
