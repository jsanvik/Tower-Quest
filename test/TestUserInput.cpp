#include <sstream>
#include "NPC.hpp"
#include "UserInput.hpp"
#include "gtest/gtest.h"

// Mock NPC classes for testing
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

// Test suite for UserInput
class UserInputTest : public ::testing::Test {
 protected:
  UserInput userInput;
  MockNPC npc{nullptr};  // Mock NPC for testing

  // Simulate input stream for tests
  std::stringstream inputStream;
  std::stringstream outputStream;

  // Helper function to set input stream for tests
  void setInput(const std::string& input) {
    inputStream.str("");  // Clear previous input
    inputStream.clear();
    inputStream << input;
  }
};

// Test for getInput()
TEST_F(UserInputTest, GetInput_Success) {
  setInput("Test input");

  std::string result = userInput.getInput(inputStream, outputStream);

  EXPECT_EQ(result, "Test input");
  EXPECT_EQ(outputStream.str(), "Enter input: ");
}

// Test for getNumberResponse() with valid input
TEST_F(UserInputTest, GetNumberResponse_ValidInput) {
  setInput("42");

  int result;
  result =
      userInput.getNumberResponse("Enter number: ", inputStream, outputStream);

  EXPECT_EQ(result, 42);
  EXPECT_EQ(outputStream.str(), "Enter number: ");
}

// Test for getNumberResponse() with invalid input
TEST_F(UserInputTest, GetNumberResponse_InvalidInput) {
  setInput("abc\n42");

  int result;
  result =
      userInput.getNumberResponse("Enter number: ", inputStream, outputStream);

  EXPECT_EQ(result, 42);
  EXPECT_EQ(outputStream.str(),
            "Enter number: Invalid. Please enter a valid number.\n");
}

// Test for getNumberResponse() with multiple invalid inputs
TEST_F(UserInputTest, GetNumberResponse_MultipleInvalidInputs) {
  setInput("abc\nxyz\n42");

  int result;
  result =
      userInput.getNumberResponse("Enter number: ", inputStream, outputStream);

  EXPECT_EQ(result, 42);
  EXPECT_EQ(outputStream.str(),
            "Enter number: Invalid. "
            "Please enter a valid number.\n"
            "Invalid. Please enter a valid number.\n");
}
