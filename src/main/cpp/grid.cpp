#include "grid.h"
#include <stdlib.h>

Grid::Grid(unsigned int size) {
	_size = size;
	_length = _size * _size;
	_cells = new unsigned int[_length]();
}

Grid::~Grid() {
	delete [] _cells;
}

unsigned int Grid::get(unsigned int x, unsigned int y) {
	return _cells[_size * y + x];
}

void Grid::set(unsigned int x, unsigned int y, unsigned int value) {
	_cells[_size * y + x] = value;
}

bool Grid::isZero() {
	for (unsigned int i = 0; i < _length; ++i)
	{
		if (0 != _cells[i]) {
			return false;
		}
	}

	return true;
}
