#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <utility>
#include <list>
#include "utils.h"

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

	if (cadre->board[nhead.first - 1][nhead.second - 1] != FEED) {
		return false;
	}
	
	return true;
}

bool collide(list<pair<int, int>>* snake, pair<int, int> object, CADRE* cadre) {
	
	char kind = cadre->board[object.first - 1][object.second - 1];
	
	if (kind != OBSTACLE && kind != SNAKE) {
		return false;
	}
	
	pair<int, int> head = getHead(snake, cadre);
	return (head.first == object.first && head.second == object.second);
}

bool moveRight(list<pair<int, int>>* snake, CADRE* cadre, DIMENSIONS* dims) {
	pair<int, int> head = getHead(snake, cadre);
	pair<int, int> nhead;
	nhead.first = head.first;
	nhead.second = head.second + 1;
	snake->push_front(nhead);
		
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second + 1, (short)nhead.first + 1);
		cout << SNAKE;
		return true;
	} 
	
	pair<int, int> tail = getTail(snake, cadre);
	snake->pop_back();
	gotoxy((short)tail.second + 1, (short)tail.first + 1);
	cout << EMPTY;
	gotoxy((short)nhead.second + 1, (short)nhead.first + 1);
		
	if (collide(snake, nhead, cadre) || onBorders(nhead, dims)) {
		return false;
	}
	
	cout << SNAKE;
	return true;
}

#endif