#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Environment.hpp"
#include "Inventory.hpp"
#include "NPC.hpp"

class Game {
 public:
  // Function to start the game - runs main game sequence
  void start();
  /**
   * @brief Exits the game
   */
  virtual void endGame();
  /**
   * @brief Checks if correct answer entered, if incorrect ends game
   * @param isCorrect Boolean representing if answer was correct or not
   * @param os The output stream to output text to
   */
  void handleAnswerResult(bool isCorrect, std::ostream& os);

 private:
  Inventory* inventory = nullptr;
};

#endif
