#include <utility>
#include <list>

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

void grow(list<tuple<int, int>>* snake, pair<int, int> nhead) {
	if (snake == null) {
		snake = (list<pair<int, int>>*) malloc(sizeof(list<pair<int, int>>));
	}
	
	snake->push_front(nhead);
}

bool collide(list<pair<int, int>>* snake, pair<int, int> object) {
	
	pair<int, int> head = getHead(snake);
	
	if (head == NULL) {
		return false;
	}
	
	return (head.first == object.first && head.second == object.second);
}

void moveRight(list<pair<int, int>>* snake) {
	if (snake == NULL) {
		return;
	}
	
	pair<int, int> head = getHead(snake);	
	pair<int, int> nhead;
	nhead.first = head.first;
	nhead.second = head.second + 1;
	snake->push_front(nhead);
	snake->pop_back();
}

// TODO: REFACTOR ALL SO THAT BOARD ELEMENTS WOULD BE 
// RENDERED PERFORMANTLY (MINIMUM CHANGES IN CONSE)