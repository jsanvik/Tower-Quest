#include <sstream>

#include "Character.hpp"
#include "Game.hpp"
#include "NPC.hpp"
#include "UserInput.hpp"
#include "gtest/gtest.h"

// TestGame class to override endGame because exit(0)
// sends the tests into infinite loops
class TestGame : public Game {
 public:
  void endGame() override { gameEndedFlag = true; }

  bool isGameEnded() const { return gameEndedFlag; }

 private:
  bool gameEndedFlag = false;
};

// TestableNPC class to isolate testing for helper methods
class TestableNPC : public NPC {
 public:
  TestableNPC(Game* game) : NPC(game) {}

  void dialogue(std::ostream& os) override { os << "Testable NPC dialogue"; }

  void givePuzzle(std::istream& is, std::ostream& os) override {
    os << "Testable NPC puzzle";
  }

  // Public access to protected methods for testing
  bool askMultipleChoice(std::istream& is, std::ostream& os,
                         const std::vector<std::string>& options, char answer) {
    return NPC::askMultipleChoice(is, os, options, answer);
  }
};

// Test fixture for NPC tests, sets up the inputstream
// helping with input simulation
class TestNPC : public ::testing::Test {
 protected:
  UserInput userInput;
  std::stringstream inputStream;

  void setInput(const std::string& input) {
    inputStream.str("");
    inputStream.clear();
    inputStream << input;
  }
};

// Test for askMultipleChoice helper method
TEST_F(TestNPC, AskMultipleChoice_SingleOption) {
  Game game;
  TestableNPC npc(&game);

  std::stringstream ss;
  std::vector<std::string> options = {"Option A"};

  // Test single option and valid answer
  setInput("A");
  EXPECT_TRUE(npc.askMultipleChoice(inputStream, ss, options, 'A'));
}

// Test for askMultipleChoice helper method
TEST_F(TestNPC, AskMultipleChoice_ValidAnswerAndCaseInsensitivity) {
  Game game;
  TestableNPC npc(&game);

  // Test valid answer
  setInput("B");
  std::stringstream ss;
  std::vector<std::string> options = {"Option A", "Option B", "Option C"};
  EXPECT_TRUE(npc.askMultipleChoice(inputStream, ss, options, 'B'));

  // Test case insensitivity
  setInput("b");
  EXPECT_TRUE(npc.askMultipleChoice(inputStream, ss, options, 'B'));
}

// Test for askMultipleChoice helper method
TEST_F(TestNPC, AskMultipleChoice_OutOfRangeInput) {
  Game game;
  TestableNPC npc(&game);

  std::stringstream ss;
  std::vector<std::string> options = {"Option A", "Option B", "Option C"};

  // Test invalid out-of-range input
  setInput("D");
  npc.askMultipleChoice(inputStream, ss, options, 'B');

  EXPECT_NE(ss.str().find("Invalid "), std::string::npos);

  setInput("B");
  EXPECT_TRUE(npc.askMultipleChoice(inputStream, ss, options, 'B'));
}

// Test for askMultipleChoice helper method
TEST_F(TestNPC, AskMultipleChoice_InvalidInputWithRetries) {
  Game game;
  TestableNPC npc(&game);

  std::stringstream ss;
  std::vector<std::string> options = {"Option A", "Option B", "Option C"};

  // Simulate invalid input for retries (3 invalid inputs)
  setInput(" ");  // Invalid input (1st attempt)
  npc.askMultipleChoice(inputStream, ss, options, 'B');
  EXPECT_NE(ss.str().find("Invalid"), std::string::npos);

  // Simulate another invalid input
  setInput("Y");  // Invalid input (2nd attempt)
  npc.askMultipleChoice(inputStream, ss, options, 'B');
  EXPECT_NE(ss.str().find("Invalid choice."), std::string::npos);

  // Simulate another invalid input
  setInput("Z");  // Invalid input (3rd attempt)
  npc.askMultipleChoice(inputStream, ss, options, 'B');
  EXPECT_NE(ss.str().find("Invalid choice."), std::string::npos);

  EXPECT_NE(ss.str().find("Maximum attempts "), std::string::npos);
}

// Test for Guard dialogue
TEST_F(TestNPC, GuardDialogue) {
  Game game;
  Guard guard(&game);
  std::stringstream ss;

  guard.dialogue(ss);

  std::string expectedOutput =
      "Guard: Halt! You seek to rescue the princess, "
      "but you shall not pass so easily.\n"
      "The gate to the tower will remain "
      "sealed until you prove your intellect.\n";
  EXPECT_EQ(ss.str(), expectedOutput);
}

// Test for Guard givePuzzle
TEST_F(TestNPC, GuardPuzzle_CorrectAnswer) {
  Game game;
  Guard guard(&game);
  Character character;

  guard.setCharacter(&character);

  setInput("96");

  std::stringstream ss;
  guard.givePuzzle(inputStream, ss);

  EXPECT_TRUE(character.getInventory()->hasItem("Flaming Sword"));
  EXPECT_NE(ss.str().find("Enchanted Mysterious Sword"), std::string::npos);
}

// Test for Guard givePuzzle
TEST_F(TestNPC, GuardPuzzle_WrongAnswer) {
  TestGame game;
  Guard guard(&game);
  Character character;

  guard.setCharacter(&character);

  setInput("42");

  std::stringstream ssWrong;
  guard.givePuzzle(inputStream, ssWrong);

  EXPECT_FALSE(character.getInventory()->hasItem("Flaming Sword"));
  EXPECT_NE(ssWrong.str().find("Incorrect."), std::string::npos);
  EXPECT_TRUE(game.isGameEnded());
}

// Test for Librarian dialogue
TEST_F(TestNPC, LibrarianDialogue) {
  Game game;
  Librarian librarian(&game);
  std::stringstream ss;

  librarian.dialogue(ss);

  std::string expectedOutput =
      "Librarian: To keep ascending the tower, "
      "your mind must be sharper than your blade.\n";
  EXPECT_EQ(ss.str(), expectedOutput);
}

// Test for Librarian givePuzzle
TEST_F(TestNPC, LibrarianPuzzle_CorrectAnswer) {
  Game game;
  Librarian librarian(&game);
  Character character;

  librarian.setCharacter(&character);

  setInput("B");

  std::stringstream ss;
  librarian.givePuzzle(inputStream, ss);

  EXPECT_NE(ss.str().find("Correct!\n"),
            std::string::npos);
}

// Test for Librarian givePuzzle
TEST_F(TestNPC, LibrarianPuzzle_WrongAnswer) {
  TestGame game;
  Librarian librarian(&game);
  Character character;

  librarian.setCharacter(&character);

  setInput("A");

  std::stringstream ss;
  librarian.givePuzzle(inputStream, ss);

  EXPECT_NE(ss.str().find("Incorrect"), std::string::npos);
  EXPECT_TRUE(game.isGameEnded());
}

// Test for Dementors dialogue
TEST_F(TestNPC, DementorsDialogue) {
  Game game;
  Dementors dementors(&game);
  std::stringstream ss;

  dementors.dialogue(ss);

  std::string expectedOutput =
      "Dementor: The darkness is overwhelming. "
      "You cannot see the door ahead.\n"
      "To get past you need to navigate this dark room.\n";
  EXPECT_EQ(ss.str(), expectedOutput);
}

// Test for Dementors givePuzzle
TEST_F(TestNPC, DementorsPuzzle_CorrectAnswer_WithFlamingSword) {
  Game game;
  Dementors dementor(&game);
  Character character;

  dementor.setCharacter(&character);

  std::shared_ptr<Item> flamingSword =
      std::make_shared<FlamingSword>("Flaming Sword");
  character.getInventory()->addItem(flamingSword);

  setInput("C\nL\n");

  std::stringstream ss;
  dementor.givePuzzle(inputStream, ss);

  EXPECT_TRUE(character.getInventory()->hasItem("Flaming Sword"));
  EXPECT_NE(ss.str().find("You wield the Flaming Sword!"), std::string::npos);
  EXPECT_NE(ss.str().find("The room lights up, "
                          "revealing the door behind you."),
            std::string::npos);
  EXPECT_NE(ss.str().find("You may now proceed to the next room."),
            std::string::npos);
}

// Test for Dementors givePuzzle
TEST_F(TestNPC, DementorsPuzzle_CorrectAnswer_WithoutFlamingSword) {
  Game game;
  Dementors dementor(&game);
  Character character;

  dementor.setCharacter(&character);

  setInput("C\nL\n");

  std::stringstream ss;
  dementor.givePuzzle(inputStream, ss);

  EXPECT_FALSE(character.getInventory()->hasItem("Flaming Sword"));
  EXPECT_NE(ss.str().find("You don't have the Flaming Sword! "
                          "The darkness remains, and you cannot proceed.\n"),
            std::string::npos);
}

// Test for Dementors givePuzzle
TEST_F(TestNPC, DementorsPuzzle_WrongAnswer) {
  TestGame game;
  Dementors dementor(&game);
  Character character;

  dementor.setCharacter(&character);

  setInput("A");

  std::stringstream ss;
  dementor.givePuzzle(inputStream, ss);

  EXPECT_NE(ss.str().find("Incorrect"), std::string::npos);
  EXPECT_TRUE(game.isGameEnded());
}

// Test for Dementors givePuzzle
TEST_F(TestNPC, DementorsPuzzle_InvalidLightCommand) {
  Game game;
  Dementors dementor(&game);
  Character character;

  dementor.setCharacter(&character);

  std::shared_ptr<Item> flamingSword =
      std::make_shared<FlamingSword>("Flaming Sword");
  character.getInventory()->addItem(flamingSword);

  setInput("C\nX\nL\n");

  std::stringstream ss;
  dementor.givePuzzle(inputStream, ss);

  EXPECT_TRUE(character.getInventory()->hasItem("Flaming Sword"));
  EXPECT_NE(ss.str().find("Invalid input. Try again by pressing 'L'."),
            std::string::npos);
  EXPECT_NE(ss.str().find("The room lights up, "
                          "revealing the door behind you."),
            std::string::npos);
}

// Test for Witch dialogue
TEST_F(TestNPC, WitchDialogue) {
  Game game;
  Witch witch(&game);
  std::stringstream ss;

  witch.dialogue(ss);

  std::string expectedOutput =
      "Witch: Before you take what you seek, "
      "you must prove your worth again and again.\n"
      "Another puzzle for you, brave knight, "
      "to test the strength of the mind as much as the heart.\n";
  EXPECT_EQ(ss.str(), expectedOutput);
}

// Test for Witch givePuzzle
TEST_F(TestNPC, WitchPuzzle_CorrectAnswer) {
  Game game;
  Witch witch(&game);
  Character character;

  witch.setCharacter(&character);

  setInput("A");

  std::stringstream ss;
  witch.givePuzzle(inputStream, ss);

  EXPECT_TRUE(character.getInventory()->hasItem("Good Potion"));
  EXPECT_NE(ss.str().find("The Witch has given you a mysterious potion."),
            std::string::npos);
  EXPECT_NE(ss.str().find("Its nature remains unknown..."), std::string::npos);
}

// Test for Witch givePuzzle
TEST_F(TestNPC, WitchPuzzle_IncorrectAnswer) {
  Game game;
  Witch witch(&game);
  Character character;

  witch.setCharacter(&character);

  setInput("B");

  std::stringstream ss;
  witch.givePuzzle(inputStream, ss);

  EXPECT_TRUE(character.getInventory()->hasItem("Bad Potion"));
  EXPECT_NE(ss.str().find("The Witch has given you a mysterious potion."),
            std::string::npos);
  EXPECT_NE(ss.str().find("Its nature remains unknown..."), std::string::npos);
}

// Test for Princess dialogue
TEST_F(TestNPC, PrincessDialogue) {
  Game game;
  Princess princess(&game);
  std::stringstream ss;

  princess.dialogue(ss);

  std::string expectedOutput =
      "The princess lies in deep slumber.\n"
      "Her face soft and untouched by time, "
      "as if the years had no hold over her.\n"
      "Finally.. You have made it here.\n";
  EXPECT_EQ(ss.str(), expectedOutput);
}

// Test for Princess givePuzzle
TEST_F(TestNPC, PrincessPuzzle_CorrectDecision_WithGoodPotion) {
  Game game;
  Princess princess(&game);
  Character character;

  princess.setCharacter(&character);

  std::shared_ptr<Item> goodPotion =
      std::make_shared<GoodPotion>("Good Potion");
  character.getInventory()->addItem(goodPotion);

  setInput("A");

  std::stringstream ss;
  princess.givePuzzle(inputStream, ss);

  // EXPECT_FALSE to check if the potion has been used
  EXPECT_FALSE(character.getInventory()->hasItem("Good Potion"));
  EXPECT_NE(ss.str().find("The princess opens her eyes "), std::string::npos);
}

// Test for Princess givePuzzle
TEST_F(TestNPC, PrincessPuzzle_CorrectDecision_WithBadPotion) {
  TestGame game;
  Princess princess(&game);
  Character character;

  princess.setCharacter(&character);

  std::shared_ptr<Item> badPotion = std::make_shared<BadPotion>("Bad Potion");
  character.getInventory()->addItem(badPotion);

  setInput("A");

  std::stringstream ss;
  princess.givePuzzle(inputStream, ss);

  // EXPECT_FALSE to check if the potion has been used
  EXPECT_FALSE(character.getInventory()->hasItem("Bad Potion"));
  EXPECT_NE(ss.str().find("The princess died. You lose."), std::string::npos);
  EXPECT_TRUE(game.isGameEnded());
}

// Test for Princess givePuzzle
TEST_F(TestNPC, PrincessPuzzle_IncorrectDecision_Deny) {
  TestGame game;
  Princess princess(&game);
  Character character;

  princess.setCharacter(&character);

  std::shared_ptr<Item> goodPotion =
      std::make_shared<GoodPotion>("Good Potion");
  character.getInventory()->addItem(goodPotion);

  setInput("B");

  std::stringstream ss;
  princess.givePuzzle(inputStream, ss);

  // EXPECT_TRUE to make sure the potion has not been used
  EXPECT_TRUE(character.getInventory()->hasItem("Good Potion"));
  EXPECT_NE(ss.str().find("Incorrect"), std::string::npos);
  EXPECT_TRUE(game.isGameEnded());
}

// Test for Princess wakeUp method
TEST_F(TestNPC, PrincessWakeUp) {
  Game game;
  Princess princess(&game);

  std::stringstream ss;

  princess.wakeUp(ss);

  EXPECT_NE(ss.str().find("The princess opens her eyes and "
                          "smiles. Congratulations. You Won!\n"),
            std::string::npos);
}
