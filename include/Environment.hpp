#ifndef ENVIRONMENT_H_INCLUDED
#define ENVIRONMENT_H_INCLUDED

#include <ostream>
#include <string>
#include <vector>

#include "NPC.hpp"

/**
 * @class Environment
 * @brief An environment in the game.
 * @details is the base class for all other environments
 */
class Environment {
 protected:
  std::string name;
  std::string description;
  std::vector<Environment*> connectedEnvironments;

 public:
  /**
   * @brief Constructs an Environment object.
   * @param name The name of the environment.
   * @param description A short description of the environment.
   */
  Environment(const std::string& name, const std::string& description);
};

/**
 * @class SafeEnvironment
 * @brief Represents a safe area in the game.
 * @details SafeEnvironment is where the player is safe and will not die
 */
class SafeEnvironment : public Environment {
 public:
  /**
   * @brief Constructs a SafeEnvironment
   * @param name The name of the safe environment.
   * @param description A short description of the environment.
   */
  SafeEnvironment(const std::string& name, const std::string& description);

  /**
   * @brief Simulates a room with multiple doors.
   * @param os The output stream to display room details and prompts.
   * @param is The input stream to capture the player's choice.
   */
  void doorRoom(std::ostream& os, std::istream& is);

  /**
   * @brief Describes the front yard, the starting point of the game and the
   * game title.
   * @param os The output stream to display the front yard description.
   */
  static void frontYard(std::ostream& os);
};

/**
 * @class PuzzleEnvironment
 * @brief The area with puzzles and NPC interactions.
 * @details PuzzleEnvironment is where the player interact with NPCs to solve
 * puzzles and progress through the game.
 */
class PuzzleEnvironment : public Environment {
  NPC* npc;  // Pointer to the NPC in this environment.

 public:
  /**
   * @brief Constructs a PuzzleEnvironment
   * @param name The name of the puzzle environment.
   * @param description A short description of the environment.
   * @param npc A pointer to the NPC in the environment.
   */
  PuzzleEnvironment(const std::string& name, const std::string& description,
                    NPC* npc);

  /**
   * @brief Simulates the dark room puzzle.
   * @param os The output stream to display the room description.
   */
  void darkRoom(std::ostream& os);

  /**
   * @brief Simulates the library room puzzle.
   * @param os The output stream to display the room description.
   */
  void libraryRoom(std::ostream& os);

  /**
   * @brief Simulates the witch's cavern puzzle.
   * @param os The output stream to display the room description.
   */
  void witchCavern(std::ostream& os);

  /**
   * @brief Simulates the princess room.
   * @param os The output stream to display the room description.
   */
  void princessRoom(std::ostream& os);

  /**
   * @brief Simulates the gate area at the base of the tower.
   * @param os The output stream to display the room description.
   */
  void gate(std::ostream& os);
};

/**
 * @class DangerousEnvironment
 * @brief Environment where the player dies
 */
class DangerousEnvironment : public Environment {
 public:
  /**
   * @brief Constructs a DangerousEnvironment.
   * @param name The name of the dangerous environment.
   * @param description A short description of the environment.
   */
  DangerousEnvironment(const std::string& name, const std::string& description);

  /**
   * @brief Simulates the pit room, a dangerous area where players can fall.
   * @param os The output stream to display the room description.
   */
  static void pitRoom(std::ostream& os);

  /**
   * @brief Simulates the spike room, a deadly trap.
   * @param os The output stream to display the room description.
   */
  static void spikeRoom(std::ostream& os);
};

#endif
