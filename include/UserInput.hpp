#ifndef USERINPUT_H_INCLUDED
#define USERINPUT_H_INCLUDED

#include <iostream>
#include <string>
class NPC;

/**
 * @class UserInput
 * @brief Handles user input interactions for dialogue, puzzles, and general
 * input.
 * @details This class provides methods for obtaining responses from the user
 * during gameplay,
 * @details including getting dialogue responses, puzzle responses, and numeric
 * inputs.
 * @detailsThe class interacts with the user through the provided input and
 * output streams.
 */
class UserInput {
 public:
  /**
   * @brief Prompts the user for a general input.
   * @param is The input stream from which the user's input will be read.
   * @param os The output stream to display a prompt to the user for input.
   * @return A string containing the user's input.
   */
  std::string getInput(std::istream& is, std::ostream& os);

  /**
   * @brief Prompts the user for a numeric response.
   * @param prompt A string containing the prompt to display to the user.
   * @param is The input stream from which the numeric response will be read.
   * @param os The output stream to display the prompt to the user.
   * @return An integer representing the user's numeric response.
   */
  int getNumberResponse(const std::string& prompt, std::istream& is,
                        std::ostream& os);

 private:
  /**
   * @brief Holds the current input provided by the user.
   */
  std::string currentInput;
};

#endif
