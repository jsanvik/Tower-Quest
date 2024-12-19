#include <sstream>
#include "Game.hpp"
#include "Character.hpp"
#include "Environment.hpp"
#include "NPC.hpp"
#include "gtest/gtest.h"

class TestGame : public Game {
 public:
  void endGame() override { gameEndedFlag = true; }

  bool isGameEnded() const { return gameEndedFlag; }

 private:
  bool gameEndedFlag = false;
};

// Test for handleAnswerResult (already provided)
TEST(TestGame, HandleAnswerResult) {
  TestGame game;
  std::stringstream ss;
  game.handleAnswerResult(true, ss);
  EXPECT_EQ(ss.str(), "Correct!\n");
  EXPECT_FALSE(game.isGameEnded());

  ss.str("");
  ss.clear();
  game.handleAnswerResult(false, ss);

  EXPECT_EQ(ss.str(), "Incorrect. GAME OVER!\n");
  EXPECT_TRUE(game.isGameEnded());
}

// test for endGame method
TEST(TestGame, EndGame) {
  TestGame game;

  EXPECT_NO_THROW(game.endGame());

  EXPECT_TRUE(game.isGameEnded());
}
