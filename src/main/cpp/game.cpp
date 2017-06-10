#include "game.h"
#include "grid.h"

Game::Game(unsigned int size) {
	_size = size;
	_grid = new Grid(_size);
}

Game::~Game() {
	delete _grid;
}

void Game::up() {

	for (unsigned int x = 0; x < _size; ++x) {

		bool* modified = new bool[_size]();

		for (unsigned int y = 0; y < _size; ++y) {

			unsigned int value = _grid->get(x, y);

			if (!value) continue;

			unsigned int y1 = y;
			unsigned int value1 = value;

			for (int i = y1 - 1; i >= 0; --i)
			{
				if (modified[i]) break;

				value1 = _grid->get(x, i);

				if (value1 && value != value1) break;

				y1 = i;
			}

			if (y == y1) continue;

			if (value == value1) {
				++value;
				modified[y1] = true;
			}

			_grid->set(x, y1, value);
			_grid->set(x, y, 0);
		}

		delete [] modified;
	}
}
