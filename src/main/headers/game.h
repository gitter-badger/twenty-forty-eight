#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "grid.h"

class Game {
	public:
		Game(unsigned int);
		~Game();
		static Game* fromArray(unsigned int*);
		unsigned int* toArray();
		void up();
		void down();
		void left();
		void right();
	private:
		unsigned int _size;
		unsigned int _score;
		Grid* _grid;
};

#endif
