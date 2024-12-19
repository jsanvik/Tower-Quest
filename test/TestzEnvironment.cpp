#include <sstream>

#include "Environment.hpp"
#include "NPC.hpp"
#include "gtest/gtest.h"

// mock npc class for testing
class MockNPC : public NPC {
 public:
  MockNPC(Game* game) : NPC(game) {}
  void dialogue(std::ostream& os) override {
    os << "MockNPC: Dialogue triggered.\n";
  }
  void givePuzzle(std::istream& is, std::ostream& os) override {
    os << "MockNPC: Puzzle triggered.\n";
  }
};

// test class for environment
class EnvironmentTest : public ::testing::Test {
 protected:
  std::stringstream inputStream;
  std::stringstream outputStream;
  MockNPC mockNPC{nullptr};

  // helper to set the input stream
  void setInput(const std::string& input) {
    inputStream.str("");
    inputStream.clear();
    inputStream << input;
  }

  // helper to reset the output stream
  void resetOutput() {
    outputStream.str("");
    outputStream.clear();
  }
};

// test for frontYard
TEST_F(EnvironmentTest, FrontYardPASS) {
  SafeEnvironment environment("Front Yard", "start of the tower.");

  environment.frontYard(outputStream);

  EXPECT_EQ(
      outputStream.str(),
      "\n=======Welcome to Tower Quest========\n"
      "\n-----Front Yard-----\n"
      "\nYou stand before a tall towering structure hidden by the mist.\n"
      "You are a knight on a mission to reach the top of the tower \n"
      "and awaken the princess from her eternal slumber.\n Each room ahead "
      "presents a unique challenge.\n");
}

// test for gate
TEST_F(EnvironmentTest, GatePASS) {
  PuzzleEnvironment environment("Gate", "the base of the tower.", &mockNPC);

  environment.gate(outputStream);

  EXPECT_EQ(
      outputStream.str(),
      "\n------Gate------\n"
      "A guard blocks your way as you step into the tower's dim entrance.\n"
      "MockNPC: Dialogue triggered.\n"
      "MockNPC: Puzzle triggered.\n");
}

// test for libraryRoom
TEST_F(EnvironmentTest, LibraryRoomPASS) {
  PuzzleEnvironment environment(
      "Library Room", "a quiet library filled with ancient books.", &mockNPC);

  environment.libraryRoom(outputStream);

  EXPECT_EQ(outputStream.str(),
            "\n------Library Room------\n"
            "You enter a quiet library lined with dusty bookshelves.\n"
            "MockNPC: Dialogue triggered.\n"
            "MockNPC: Puzzle triggered.\n");
}

// test for witchCavern
TEST_F(EnvironmentTest, WitchCavernPASS) {
  PuzzleEnvironment environment("Witch Cavern", "the witch's lair.", &mockNPC);

  environment.witchCavern(outputStream);

  EXPECT_EQ(outputStream.str(),
            "\n------Witch's Cavern------\n"
            "Flickering lights and whispers fill the cavern as you enter.\n"
            "MockNPC: Dialogue triggered.\n"
            "MockNPC: Puzzle triggered.\n");
}

// test for princessRoom
TEST_F(EnvironmentTest, PrincessRoomPASS) {
  PuzzleEnvironment environment("Princess Room", "the final room of the tower.",
                                &mockNPC);

  environment.princessRoom(outputStream);

  EXPECT_EQ(outputStream.str(),
            "\n------Princess Room------\n"
            "At the tower's peak, the princess lies in an eternal slumber.\n"
            "MockNPC: Dialogue triggered.\n"
            "MockNPC: Puzzle triggered.\n");
}

// test for darkRoom
TEST_F(EnvironmentTest, darkRoomPASS) {
  PuzzleEnvironment environment("Dark Room", "Super dark room", &mockNPC);

  environment.darkRoom(outputStream);

  EXPECT_EQ(outputStream.str(),
            "\n------ Dark Room------\n"
            "A pitch-black room greets you with silence and an eerie chill.\n"
            "MockNPC: Dialogue triggered.\n"
            "MockNPC: Puzzle triggered.\n");
}

// test for pit room
TEST_F(EnvironmentTest, pitRoomPASS) {
  DangerousEnvironment environment("Pit Room", "Long way down!");

  environment.pitRoom(outputStream);

  EXPECT_EQ(outputStream.str(),
            "The ground gives way beneath you, and you fall endlessly. Game "
            "over!\n");
}

// test for spike room
TEST_F(EnvironmentTest, spikeRoomPASS) {
  DangerousEnvironment environment("Spike Room", "Ouch!");

  environment.spikeRoom(outputStream);

  EXPECT_EQ(outputStream.str(),
            "The ground gives way beneath you, and you fall endlessly. Game "
            "over!");
}
