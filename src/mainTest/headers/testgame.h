#ifndef TESTGAME_H_INCLUDED
#define TESTGAME_H_INCLUDED

#include "game.h"
#include <gtest/gtest.h>

class GameTest : public ::testing::Test {
	protected:
		virtual void SetUp();
		virtual void TearDown();
		Game* _game;	
};

#endif
