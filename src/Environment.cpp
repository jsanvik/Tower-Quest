/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include "Environment.hpp"
#include <iostream>
#include <string>
#include "Character.hpp"
#include "NPC.hpp"
#include "Game.hpp"

Environment::Environment(const std::string& name,
                         const std::string& description)
    : name(name), description(description) {}
SafeEnvironment::SafeEnvironment(const std::string& name,
                                 const std::string& description)
    : Environment(name, description) {}

PuzzleEnvironment::PuzzleEnvironment(const std::string& name,
                                     const std::string& description, NPC* npc)
    : Environment(name, description), npc(npc) {}

DangerousEnvironment::DangerousEnvironment(const std::string& name,
                                           const std::string& description)
    : Environment(name, description) {}

void SafeEnvironment::frontYard(std::ostream& os) {
  os << "\n=======Welcome to Tower Quest========\n";
  os << "\n-----Front Yard-----\n";
  os << "\nYou stand before a tall towering structure hidden by the mist.\n";
  os << "You are a knight on a mission to reach the top of the tower \n"
        "and awaken the princess from her eternal slumber.\n Each room ahead "
        "presents a unique challenge.\n";
}

void PuzzleEnvironment::gate(std::ostream& os) {
  os << "\n------Gate------\n";
  os << "A guard blocks your way as you step into the tower's dim entrance.\n";
  if (npc) {
    npc->dialogue(os);
    npc->givePuzzle(std::cin, os);
  }
}
void PuzzleEnvironment::libraryRoom(std::ostream& os) {
  os << "\n------Library Room------\n";
  os << "You enter a quiet library lined with dusty bookshelves.\n";
  if (npc) {
    npc->dialogue(os);
    npc->givePuzzle(std::cin, os);
  }
}

void PuzzleEnvironment::darkRoom(std::ostream& os) {
  os << "\n------ Dark Room------\n";
  os << "A pitch-black room greets you with silence and an eerie chill.\n";
  if (npc) {
    npc->dialogue(os);
    npc->givePuzzle(std::cin, os);
  }
}

void PuzzleEnvironment::witchCavern(std::ostream& os) {
  os << "\n------Witch's Cavern------\n";
  os << "Flickering lights and whispers fill the cavern as you enter.\n";
  if (npc) {
    npc->dialogue(os);
    npc->givePuzzle(std::cin, os);
  }
}

void PuzzleEnvironment::princessRoom(std::ostream& os) {
  os << "\n------Princess Room------\n";
  os << "At the tower's peak, the princess lies in an eternal slumber.\n";
  if (npc) {
    npc->dialogue(os);
    npc->givePuzzle(std::cin, os);
  }
}

void SafeEnvironment::doorRoom(std::ostream& os, std::istream& is) {
  os << "\n------Door Room------\n";
  os << "Three doors stand before you, each marked with a cryptic symbol.\n";
  os << "The inscription reads: \"Each door leads to your destiny. Choose "
        "wisely.\"\n";
  os << "Options: [1] [2] [3] \n";
  os << "-> ";
  std::string choice;
  std::getline(is, choice);

  if (choice == "1") {
    DangerousEnvironment::spikeRoom(os);
  } else if (choice == "2") {
    DangerousEnvironment::pitRoom(os);
  } else if (choice == "3") {
    os << "You chose the correct door! You proceed to the next room.\n";
    // PuzzleEnvironment witchCavern("Witch's Cavern", "Flickering lights and
    // whispers fill the cavern as you enter.", nullptr);
    // witchCavern.witchCavern(os);
  } else {
    os << "Invalid choice. Try again.\n";
    doorRoom(os, is);
  }
}

void DangerousEnvironment::spikeRoom(std::ostream& os) {
  Game game;
  os << "The floor collapses, and you fall into a pit of spikes. Game over!\n";
  game.endGame();
}

void DangerousEnvironment::pitRoom(std::ostream& os) {
  Game game;
  os << "The ground gives way beneath you, and you fall endlessly. Game "
        "over!\n";
  game.endGame();
}
