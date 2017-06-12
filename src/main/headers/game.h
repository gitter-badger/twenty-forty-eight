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
	private:
		unsigned int _size;
		Grid* _grid;
};

#endif
