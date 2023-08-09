#ifndef INTERACTION_MANAGER
#define INTERACTION_MANAGER

#define EXIT 'X'
#define LETTER_NUMBER 32
#define CONFIRM 'Y'
#define NOT_SURE 'N'
#define CARRIAGE_RETURN '\n'


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


#endif
