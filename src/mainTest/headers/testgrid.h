#ifndef TESTGRID_H_INCLUDED
#define TESTGRID_H_INCLUDED

#include "grid.h"
#include <gtest/gtest.h>

class GridTest : public ::testing::Test {
	protected:
		virtual void SetUp();
		virtual void TearDown();
		Grid* _grid;
};

#endif
