#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Character.hpp"
#include "Item.hpp"
#include "UserInput.hpp"
class Game;

/**
 * @class NPC NPC.hpp
 * @brief Abstract base class for Non-Player Characters (NPCs) in the game.
 * @details This class defines the interface for NPCs, including methods for
 * dialogue and puzzles.
 * @details It maintains a pointer to the Game and Character objects associated
 * with the NPC.
 * @details Subclasses of NPC implement specific dialogue and puzzle-giving
 * behavior.
 */
class NPC {
 public:
  /**
   * @brief Constructor that associates the NPC with a game.
   * @param[in] game A pointer to the Game object this NPC belongs to.
   */
  NPC(Game* game);
  /**
   * @brief Virtual destructor for proper cleanup of derived classes.
   */
  virtual ~NPC() = default;

  /**
   * @brief Associates a Character with the NPC.
   * @param[in] character A pointer to the Character object associated with the
   * NPC.
   */
  void setCharacter(Character* character);

  /**
   * @brief Virtual method for the NPC to speak dialogue.
   * @param[in] os The output stream where the dialogue will be written.
   * @details This method must be overridden by subclasses to provide specific
   * dialogue.
   */
  virtual void dialogue(std::ostream& os) = 0;

  /**
   * @brief Virtual method for the NPC to give a puzzle.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   * @details This method must be overridden by subclasses to provide specific
   * puzzles.
   */
  virtual void givePuzzle(std::istream& is, std::ostream& os = std::cout) = 0;

 protected:
  /**
   * @brief A pointer to the Game object this NPC belongs to.
   */
  Game* game;
  /**
   * @brief A pointer to the Character associated with this NPC.
   */
  Character* character;

  /**
   * @brief A pointer to the UserInput object for interacting with the NPC.
   */
  std::unique_ptr<UserInput> userInput;

  /**
   * @brief Displays a multiple-choice question to the player and evaluates
   * their answer.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream to print the question and options.
   * @param[in] options A list of options for the multiple-choice question.
   * @param[in] correctAnswer The correct answer choice character.
   * @return true if the player's answer is correct, false otherwise.
   */
  bool askMultipleChoice(std::istream& is, std::ostream& os,
                         const std::vector<std::string>& options,
                         char correctAnswer);

  /**
   * @brief Handles the result of the player's answer (correct or incorrect).
   * @param[in] isCorrect Indicates whether the player's answer was correct.
   * @param[in] os The output stream where the result will be printed.
   */
  void handleAnswerResult(bool isCorrect, std::ostream& os);
};

/**
 * @class Guard Guard.hpp
 * @brief Derived class for the Guard NPC.
 */
class Guard : public NPC {
 public:
  /**
   * @brief Constructor for the Guard NPC.
   * @param[in] game A pointer to the Game object this Guard belongs to.
   */
  Guard(Game* game) : NPC(game) {}

  /**
   * @brief Provides the Guard's dialogue to the player.
   * @param[in] os The output stream where the dialogue will be written.
   */
  void dialogue(std::ostream& os) override;

  /**
   * @brief Gives a puzzle for the Guard NPC.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   */
  void givePuzzle(std::istream& is, std::ostream& os = std::cout) override;
};

/**
 * @class Librarian Librarian.hpp
 * @brief Derived class for the Librarian NPC.
 */
class Librarian : public NPC {
 public:
  /**
   * @brief Constructor for the Librarian NPC.
   * @param[in] game A pointer to the Game object this Librarian belongs to.
   */
  Librarian(Game* game) : NPC(game) {}

  /**
   * @brief Provides the Librarian's dialogue to the player.
   * @param[in] os The output stream where the dialogue will be written.
   */
  void dialogue(std::ostream& os = std::cout) override;

  /**
   * @brief Gives a puzzle for the Librarian NPC.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   */
  void givePuzzle(std::istream& is, std::ostream& os = std::cout) override;
};

/**
 * @class Dementors Dementors.hpp
 * @brief Derived class for the Dementors NPC.
 */
class Dementors : public NPC {
 public:
  /**
   * @brief Constructor for the Dementors NPC.
   * @param[in] game A pointer to the Game object this Dementors belongs to.
   */
  Dementors(Game* game) : NPC(game) {}

  /**
   * @brief Provides the Dementors' dialogue to the player.
   * @param[in] os The output stream where the dialogue will be written.
   */
  void dialogue(std::ostream& os) override;

  /**
   * @brief Gives a puzzle for the Dementors NPC.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   */
  void givePuzzle(std::istream& is, std::ostream& os = std::cout) override;
};

/**
 * @class Witch Witch.hpp
 * @brief Derived class for the Witch NPC.
 */
class Witch : public NPC {
 public:
  /**
   * @brief Constructor for the Witch NPC.
   * @param[in] game A pointer to the Game object this Witch belongs to.
   */
  Witch(Game* game) : NPC(game) {}

  /**
   * @brief Provides the Witch's dialogue to the player.
   * @param[in] os The output stream where the dialogue will be written.
   */
  void dialogue(std::ostream& os) override;

  /**
   * @brief Gives a puzzle for the Witch NPC.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   */
  void givePuzzle(std::istream& is, std::ostream& os = std::cout) override;
};

/**
 * @class Princess Princess.hpp
 * @brief Derived class for the Princess NPC.
 */
class Princess : public NPC {
 public:
  /**
   * @brief Constructor for the Princess NPC.
   * @param[in] game A pointer to the Game object this Princess belongs to.
   */
  Princess(Game* game) : NPC(game) {}

  /**
   * @brief Provides the Princess' dialogue to the player.
   * @param[in] os The output stream where the dialogue will be written.
   */
  void dialogue(std::ostream& os) override;

  /**
   * @brief Gives a puzzle for the Princess NPC.
   * @param[in] is The input stream for userinput and test inputs.
   * @param[in] os The output stream where the puzzle will be printed. Defaults
   * to std::cout.
   */
  void givePuzzle(std::istream& is, std::ostream& os = std::cout) override;

  /**
   * @brief Awakens the Princess from her slumber.
   * @param[in] os The output stream where the wake-up message will be printed.
   */
  void wakeUp(std::ostream& os);
};

#endif
