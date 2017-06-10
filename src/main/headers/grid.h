#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class Grid {
	public:
		Grid(unsigned int);
		~Grid();
		unsigned int get(unsigned int, unsigned int);
		void set(unsigned int, unsigned int, unsigned int);
		bool isZero();
	private:
		unsigned int _size;
		unsigned int _length;
		unsigned int* _cells;
};

#endif
