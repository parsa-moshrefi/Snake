#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <utility>
#include <list>
using namespace std;
#include "utils.h"


int getWinningLength(DIMENSIONS* dims) {
	return dims->height * dims->width * FEED_PERCENT;
}

pair<int, int> getHead(list<pair<int, int>>* snake, CADRE* cadre) {
	if (snake == NULL) {
		snake = new list<pair<int, int>>();
	}
	
	if (snake->size() == 0) {
		pair<int, int>* headPtr = new pair<int, int>(cadre->origw, cadre->origh); 
		snake->push_front(*headPtr);
	}
	
	return snake->front();
}

pair<int, int> getTail(list<pair<int, int>>* snake, CADRE* cadre) {
	if (snake == NULL) {
		snake = new list<pair<int, int>>();
	}
	
	if (snake->size() == 0) {
		pair<int, int>* tailPtr = new pair<int, int>(cadre->origw, cadre->origh); 
		snake->push_back(*tailPtr);
	}
	
	return snake->back();
}

bool isGrowable(list<pair<int, int>>* snake, pair<int, int> nhead, CADRE* cadre) {
	
	pair<int, int> head = getHead(snake, cadre);
	
	if (head.first != nhead.first && head.second != nhead.second) {
		return false;
	}

	if (cadre->board[nhead.first][nhead.second] != FEED) {
		return false;
	}
	
	return true;
}

bool collide(list<pair<int, int>>* snake, CADRE* cadre) {
	bool selfCollision = false;
	pair<int, int> head = getHead(snake, cadre);
	char kind = cadre->board[head.first][head.second];
	int hingeCounter = 1;
	
	if (kind == OBSTACLE || kind == SNAKE) {
		return true;
	}
	
	for (list<pair<int, int>>::reverse_iterator rit=snake->rbegin(); rit!=snake->rend() && hingeCounter++ != snake->size(); rit++) {

		if (rit->first == head.first && rit->second == head.second) {
			selfCollision = true;
			break;
		}
	}
	
	return selfCollision;
}

int moveRight(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	pair<int, int> head = getHead(snake, cadre);
	pair<int, int> nhead;
	nhead.first = head.first;
	nhead.second = head.second+1;	
	snake->push_front(nhead);
		
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second+1, (short)nhead.first+1);
		cout << SNAKE;
		return GROWTH;
	} 
	
	pair<int, int> tail = getTail(snake, cadre);
	snake->pop_back();
	gotoxy((short)tail.second+1, (short)tail.first+1);
	cout << EMPTY;
			
	if (collide(snake, cadre) || onBorders(nhead, dims)) {
		return LOUSED;
	}			
			
	gotoxy((short)nhead.second+1, (short)nhead.first+1);
	cout << SNAKE;
	
	if (snake->size() == getWinningLength(dims)) {
		return WONE;
	}
	
	return UNKNOWN;
}

int moveLeft(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	pair<int, int> head = getHead(snake, cadre);
	pair<int, int> nhead;
	nhead.first = head.first;
	nhead.second = head.second-1;
	snake->push_front(nhead);
	
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second+1, (short)nhead.first+1);
		cout << SNAKE;
		gotoxy((short)nhead.second, (short)nhead.first+1);
		return GROWTH;
	}
	
	pair<int, int> tail = getTail(snake, cadre);
	snake->pop_back();
	gotoxy((short)tail.second+1, (short)tail.first+1);
	cout << EMPTY;	
	
	gotoxy((short)nhead.second+1, (short)nhead.first+1);
	cout << SNAKE;
	gotoxy((short)nhead.second, (short)nhead.first+1);

	if (collide(snake, cadre) || onBorders(nhead, dims)) {
		return LOUSED;
	}			
	
	if (snake->size() == getWinningLength(dims)) {
		return WONE;
	}

	return UNKNOWN;
}

int moveUp(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	pair<int, int> head = getHead(snake, cadre);
	pair<int, int> nhead;
	nhead.first = head.first-1;
	nhead.second = head.second;
	snake->push_front(nhead);
	
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second+1, (short)nhead.first+1);
		cout << SNAKE;
		gotoxy((short)nhead.second+1, (short)nhead.first);
		return GROWTH;
	}
	
	pair<int, int> tail = getTail(snake, cadre);
	snake->pop_back();
	gotoxy((short)tail.second+1, (short)tail.first+1);
	cout << EMPTY;
	
	gotoxy((short)nhead.second+1, (short)nhead.first+1);
	cout << SNAKE;
	gotoxy((short)nhead.second+1, (short)nhead.first);
	
	if (collide(snake, cadre) || onBorders(nhead, dims)) {
		return LOUSED;
	}
	
	if (snake->size() == getWinningLength(dims)) {
		return WONE;
	}
	
	return UNKNOWN;
}

int moveDown(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	pair<int, int> head = getHead(snake, cadre);
	pair<int, int> nhead;
	nhead.first = head.first+1;
	nhead.second = head.second;
	snake->push_front(nhead);
	
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second+1, (short)nhead.first+1);
		cout << SNAKE;
		gotoxy((short)nhead.second+1, (short)nhead.first+2);
		return GROWTH;
	}
	
	pair<int, int> tail = getTail(snake, cadre);
	snake->pop_back();
	gotoxy((short)tail.second+1, (short)tail.first+1);
	cout << EMPTY;
	
	gotoxy((short)nhead.second+1, (short)nhead.first+1);
	cout << SNAKE;
	gotoxy((short)nhead.second+1, (short)nhead.first+2);
	
	if (collide(snake, cadre) || onBorders(nhead, dims)) {
		return LOUSED;
	}
	
	if (snake->size() == getWinningLength(dims)) {
		return WONE;
	}
	
	return UNKNOWN;
}

#endif