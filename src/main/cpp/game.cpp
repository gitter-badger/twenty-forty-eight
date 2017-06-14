#include "game.h"
#include "grid.h"

Game::Game(unsigned int size) {
	_size = size;
	_grid = new Grid(_size);
}

Game::~Game() {
	delete _grid;
}

Game* Game::fromArray(unsigned int* array) {

	unsigned int size = array[0];

	Game* game = new Game(size);

	for (unsigned int y = 0; y < size; ++y)
	{
		for (unsigned int x = 0; x < size; ++x)
		{
			unsigned int value = array[1 + x + size * y];
			game->_grid->set(x, y, value);
		}
	}

	return game;
}

unsigned int* Game::toArray() {

	unsigned int* array = new unsigned int[1 + _size * _size];

	array[0] = _size;

	for (unsigned int y = 0; y < _size; ++y)
	{
		for (unsigned int x = 0; x < _size; ++x)
		{
			unsigned int value = _grid->get(x, y);
			array[1 + x + _size * y] = value;
		}
	}

	return array;
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

void Game::down() {

	for (unsigned int x = 0; x < _size; ++x) {

		bool* modified = new bool[_size]();

		for (int y = _size - 1; y >= 0; --y) {

			unsigned int value = _grid->get(x, y);

			if (!value) continue;

			unsigned int y1 = y;
			unsigned int value1 = value;

			for (unsigned int i = y1; i < _size; ++i)
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

void Game::left() {

	for (unsigned int y = 0; y < _size; ++y) {

		bool* modified = new bool[_size]();

		for (unsigned int x = 0; x < _size; ++x) {

			unsigned int value = _grid->get(x, y);

			if (!value) continue;

			unsigned int x1 = x;
			unsigned int value1 = value;

			for (int i = x1 - 1; i >= 0; --i)
			{
				if (modified[i]) break;

				value1 = _grid->get(i, y);

				if (value1 && value != value1) break;

				x1 = i;
			}

			if (x == x1) continue;

			if (value == value1) {
				++value;
				modified[x1] = true;
			}

			_grid->set(x1, y, value);
			_grid->set(x, y, 0);
		}

		delete [] modified;
	}
}
