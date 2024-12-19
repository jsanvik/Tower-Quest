/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include "Game.hpp"

void Game::start() {
  Game* game = new Game();

  // Game startup
  std::string playerName;
  std::cout << "Enter character name:" << std::endl;
  std::cout << "> ";
  getline(std::cin, playerName);
  Character* character = new Character(playerName);
  std::cout << "\n";
  std::cout << "Your name is : " << "Sir Knight " << playerName << "\n";

  // Front Yard
  SafeEnvironment frontYard(
      "Front Yard",
      "You stand before a tall towering structure hidden by the mist.");
  frontYard.frontYard(std::cout);

  // Gate
  Guard* guard = new Guard(game);
  guard->setCharacter(character);
  PuzzleEnvironment gate(
      "Gate",
      "A guard blocks your way as you step into the tower's dim entrance.",
      guard);
  gate.gate(std::cout);

  // Library
  Librarian* librarian = new Librarian(game);
  PuzzleEnvironment library(
      "Library", "You enter a quiet library lined with dusty bookshelves.",
      librarian);
  library.libraryRoom(std::cout);

  // Dark Room
  Dementors* dementor = new Dementors(game);
  dementor->setCharacter(character);
  PuzzleEnvironment darkRoom("Dark Room", "A pitch-black room greets you with "
  "silence and an eerie chill.", dementor); darkRoom.darkRoom(std::cout);

  // Door room
  SafeEnvironment doorRoom(
      "Door Room",
      "Three doors stand before you, each marked with a cryptic symbol.");
  doorRoom.doorRoom(std::cout, std::cin);

  // Witch's Cavern
  Witch* witch = new Witch(game);
  witch->setCharacter(character);
  PuzzleEnvironment witchCavern(
    "Witch's Cavern",
    "Flickering lights and whispers fill the cavern as you enter.", witch);
  witchCavern.witchCavern(std::cout);

  // Princess Room
  Princess* princess = new Princess(game);
  princess->setCharacter(character);
  PuzzleEnvironment princessRoom(
      "Princess's Room",
      "At the tower's peak, the princess lies in an eternal slumber.",
      princess);
  princessRoom.princessRoom(std::cout);

  delete guard;
  guard = nullptr;
  delete librarian;
  librarian = nullptr;
  delete dementor;
  dementor = nullptr;
  delete witch;
  witch = nullptr;
  delete princess;
  princess = nullptr;
  delete character;
  character = nullptr;
  delete game;
  game = nullptr;
}

void Game::handleAnswerResult(bool isCorrect, std::ostream& os) {
  if (isCorrect) {
    os << "Correct!\n";
  } else {
    os << "Incorrect. GAME OVER!\n";
    endGame();
  }
}

void Game::endGame() { exit(0); }
