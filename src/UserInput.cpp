/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include <istream>
#include <string>
#include "UserInput.hpp"
#include "NPC.hpp"

std::string UserInput::getInput(std::istream& is, std::ostream& os) {
  os << "Enter input: ";
  std::getline(is, currentInput);
  return currentInput;
}

int UserInput::getNumberResponse(const std::string& prompt, std::istream& is,
                                 std::ostream& os) {
  int response;
  os << prompt;
  while (true) {
    is >> response;
    if (is.fail()) {
      is.clear();
      is.ignore(1000, '\n');
      os << "Invalid. Please enter a valid number.\n";
    } else {
      return response;
    }
  }
}
