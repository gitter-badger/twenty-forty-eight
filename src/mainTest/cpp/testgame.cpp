#include "testgame.h"
#include "game.h"
#include <gtest/gtest.h>

void GameTest::SetUp() {
	_game = new Game(3);
}

void GameTest::TearDown() {
	delete _game;
}
