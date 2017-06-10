#include "testgrid.h"
#include "grid.h"
#include <gtest/gtest.h>

void GridTest::SetUp() {
	_grid = new Grid(2);
}

void GridTest::TearDown() {
	delete _grid;
}

TEST_F(GridTest, TestGridIsZero) {
	ASSERT_TRUE(_grid->isZero());
}

TEST_F(GridTest, TestGridIsNotZero) {
	_grid->set(1, 0, 2);
	ASSERT_FALSE(_grid->isZero());
}
