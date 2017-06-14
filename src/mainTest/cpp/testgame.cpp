#include "testgame.h"
#include "game.h"
#include <gtest/gtest.h>

TEST_F(GameTest, TestUp) {

	unsigned int* initialState = new unsigned int[17] {
		4,
		0, 0, 2, 3,
		0, 2, 2, 0,
		0, 2, 2, 0,
		1, 2, 2, 3
	};

	unsigned int* expected = new unsigned int[17] {
		4,
		1, 3, 3, 4,
		0, 2, 3, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	Game* game = Game::fromArray(initialState);
	game->up();

	unsigned int* result = game->toArray();

	for (int i = 0; i < 17; ++i)
	{
		ASSERT_EQ(expected[i], result[i]);
	}

	delete game;
	delete [] expected;
	delete [] initialState;
	delete [] result;
}

TEST_F(GameTest, TestDown) {

	unsigned int* initialState = new unsigned int[17] {
		4,
		1, 2, 2, 3,
		0, 2, 2, 0,
		0, 2, 2, 0,
		0, 0, 2, 3
	};

	unsigned int* expected = new unsigned int[17] {
		4,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 2, 3, 0,
		1, 3, 3, 4
	};

	Game* game = Game::fromArray(initialState);
	game->down();

	unsigned int* result = game->toArray();

	for (int i = 0; i < 17; ++i)
	{
		ASSERT_EQ(expected[i], result[i]);
	}

	delete game;
	delete [] expected;
	delete [] initialState;
	delete [] result;
}

TEST_F(GameTest, TestLeft) {

	unsigned int* initialState = new unsigned int[17] {
		4,
		0, 0, 0, 1,
		0, 2, 2, 2,
		2, 2, 2, 2,
		3, 0, 0, 3
	};

	unsigned int* expected = new unsigned int[17] {
		4,
		1, 0, 0, 0,
		3, 2, 0, 0,
		3, 3, 0, 0,
		4, 0, 0, 0
	};

	Game* game = Game::fromArray(initialState);
	game->left();

	unsigned int* result = game->toArray();

	for (int i = 0; i < 17; ++i)
	{
		ASSERT_EQ(expected[i], result[i]);
	}

	delete game;
	delete [] expected;
	delete [] initialState;
	delete [] result;
}

TEST_F(GameTest, TestToFromArray) {

	unsigned int* expected = new unsigned int[17] {
		4,
		1, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 3, 0,
		0, 0, 0, 4
	};

	Game* game = Game::fromArray(expected);
	unsigned int* array = game->toArray();

	for (int i = 0; i < 17; ++i)
	{
		ASSERT_EQ(expected[i], array[i]);
	}

	delete game;
	delete [] array;
	delete [] expected;
}
