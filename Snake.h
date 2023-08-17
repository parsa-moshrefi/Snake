#include <utility>
#include <list>
#include "BoardManager.h"
#include "utils.h"

pair<int, int> getHead(list<pair<int, int>>* snake) {
	if (snake == NULL || snake->size == 0) {
		return NULL;
	}
	
	return snake->front();
}

pair<int, int> getTail(list<pair<int, int>>* snake) {
	if (snake == NULL || snake->size == 0) {
		return NULL;
	}
	
	return snake->back;
}

bool isGrowable(list<pair<int, int>>* snake, pair<int, int> nhead, CADRE* cadre) {
	
	if (snake == null) {
		snake = new list<pair<int, int>>();
	}

	pair<int, int> head = snake->front();
	
	if (head != NULL && head.first != nhead.first && head.second != nhead.second) {
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
	
	pair<int, int> head = getHead(snake);
	
	if (head == NULL) {
		return false;
	}
	
	return (head.first == object.first && head.second == object.second);
}

bool moveRight(list<pair<int, int>>* snake, CADRE* cadre) {
	if (snake == NULL) {
		return false;
	}
	
	pair<int, int> head = getHead(snake);
	
	if (head == NULL) {
		return false;
	}
	
	pair<int, int> nhead;
	nhead.first = head.first;
	nhead.second = head.second + 1;
	snake->push_front(nhead);
		
	if (isGrowable(snake, nhead, cadre)) {
		gotoxy((short)nhead.second + 1, (short)nhead.first + 1);
		cout << SNAKE;
		return true;
	} 
	
	pair<int, int> tail = snake->pop_back();
	gotoxy((short)tail.second + 1, (short)tail.first + 1);
	cout << EMPTY;
	gotoxy((short)nhead.second + 1, (short)nhead.first + 1);
		
	if (collide(snake, nhead, cadre)) {
		return false;
	}
	
	cout << SNAKE;
	return true;
}