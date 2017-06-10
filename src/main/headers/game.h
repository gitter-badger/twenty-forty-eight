#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "grid.h"

class Game {
	public:
		Game(unsigned int size);
		~Game();
		void up();
	private:
		unsigned int _size;
		Grid* _grid;
};

#endif
