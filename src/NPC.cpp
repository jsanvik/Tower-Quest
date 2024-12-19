/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include <limits>
#include "NPC.hpp"
#include "Game.hpp"

NPC::NPC(Game* game) : game(game), character(nullptr),
    userInput(std::make_unique<UserInput>()) {}

void NPC::setCharacter(Character* character) {
  this->character = character;
}

// Helper function to ask a multiple choice question with error checking
bool NPC::askMultipleChoice(std::istream& is, std::ostream& os,
        const std::vector<std::string>& options, char correctAnswer) {
    int maxRetries = 3;
    int retries = 0;

    while (true) {
        os << "Options:\n";

        for (size_t i = 0; i < options.size(); ++i) {
            os << char('A' + i) << ". " << options[i] << "\n";
        }

        std::string playerAnswer = userInput->getInput(is, os);
        if (playerAnswer.empty()) {
            os << "Invalid input. Please choose a valid option (A, B, etc.).\n";
            continue;
        }

        char choice = std::toupper(playerAnswer[0]);

        if (choice < 'A' || choice >= 'A' + options.size()) {
            os << "Invalid choice. Please select "
                  "a valid option (A, B, etc.).\n";
            retries++;
            if (retries >= maxRetries) {
                os << "Maximum attempts reached. Please try again later.\n";
                return false;
            }
            continue;
        }
        return (choice == correctAnswer);
    }
}

// Guard dialogue
void Guard::dialogue(std::ostream& os) {
    os << "Guard: Halt! You seek to rescue the princess, "
    "but you shall not pass so easily.\n";
    os << "The gate to the tower will remain "
    "sealed until you prove your intellect.\n";
}

// Guard puzzle
void Guard::givePuzzle(std::istream& is, std::ostream& os) {
    int sequence[] = {3, 6, 12, 24, 48};
    int sizeOfSequence = sizeof(sequence) / sizeof(sequence[0]);
    int sequenceAns = sequence[sizeOfSequence - 1] * 2;

    os << "Behold the sequence: ";
    for (int i = 0; i < sizeOfSequence; ++i) {
        os << sequence[i] << " ";
    }
    os << "__?\n";
    os << "What comes next is the password to enter the tower.\n";

    int playerAnswer;
    playerAnswer = userInput->getNumberResponse(
      "Enter your answer: ", is, os);

    bool isCorrect = (sequenceAns == playerAnswer);
    game->handleAnswerResult(isCorrect, os);

    if (isCorrect) {
        std::shared_ptr<Item> flamingSword;
        flamingSword = std::make_shared<FlamingSword>("Flaming Sword");
        character->getInventory()->addItem(flamingSword);
        os << "The Guard has given you a Enchanted Mysterious Sword! "
        "It may serve you well on your journey.\n";
    }

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Librarian dialogue
void Librarian::dialogue(std::ostream& os) {
    os << "Librarian: To keep ascending the tower, "
    "your mind must be sharper than your blade.\n";
}

// Librarian puzzle
void Librarian::givePuzzle(std::istream& is, std::ostream& os) {
    char correctAnswer = 'B';
    std::string scrambledWord = "dsimwo";
    std::vector<std::string> multipleChoice;
    multipleChoice = {"widsom", "wisdom", "domwis", "dowmis"};

    os << "Rearrange the letters and reveal the hidden word: "
       << scrambledWord << "\n";

    bool isCorrect = askMultipleChoice(is, os, multipleChoice, correctAnswer);
    game->handleAnswerResult(isCorrect, os);
}

// Dementors dialogue
void Dementors::dialogue(std::ostream& os) {
    os << "Dementor: The darkness is overwhelming. "
    "You cannot see the door ahead.\n";
    os << "To get past you need to navigate this dark room.\n";
}

// Dementors puzzle
void Dementors::givePuzzle(std::istream& is, std::ostream& os) {
    char correctItem = 'C';
    std::vector<std::string> multipleChoice;
    multipleChoice = {"Coins", "Shield", "Flaming Sword"};

    os << "What item might help you?\n";

    bool isCorrect = askMultipleChoice(is, os, multipleChoice, correctItem);
    game->handleAnswerResult(isCorrect, os);

    if (character->getInventory()->hasItem("Flaming Sword")) {
      os << "You wield the Flaming Sword!\n";
      os << "Press 'L' to light up the room.\n";

      std::string choice;
        do {
          is >> choice;
          choice[0] = std::toupper(choice[0]);

            if (choice == "L") {
              os << "The room lights up, "
                "revealing the door behind you.\n";
              os << "You may now proceed to the next room.\n";
            } else {
              os << "Invalid input. Try again by pressing 'L'.\n";
            }
        } while (choice != "L");
    } else {
      os << "You don't have the Flaming Sword! "
      "The darkness remains, and you cannot proceed.\n";
    }
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Witch dialogue
void Witch::dialogue(std::ostream& os) {
    os << "Witch: Before you take what you seek, "
    "you must prove your worth again and again.\n";
    os << "Another puzzle for you, brave knight, "
    "to test the strength of the mind as much as the heart.\n";
}

// Witch puzzle
void Witch::givePuzzle(std::istream& is, std::ostream& os) {
    char correctConnection = 'A';
    std::vector<std::string> associationWords = {"Moon", "Crows", "Sun"};
    std::vector<std::string> multipleChoice = {"Sky", "Celestial", "Darkness"};

    os << "Here is the test of association:\n";
    for (const auto& associationWord : associationWords) {
        os << associationWord << " ";
    }
    os << "\nWhat is the connection between them?\n";

    bool isCorrect = askMultipleChoice(is, os,
                                      multipleChoice, correctConnection);

    std::shared_ptr<Item> potion;
    if (isCorrect) {
        potion = std::make_shared<GoodPotion>("Good Potion");
    } else {
        potion = std::make_shared<BadPotion>("Bad Potion");
    }

    character->getInventory()->addItem(potion);
    os << "The Witch has given you a mysterious potion. "
    "Its nature remains unknown...\n";
}

// Princess dialogue
void Princess::dialogue(std::ostream& os) {
    os << "The princess lies in deep slumber.\n";
    os << "Her face soft and untouched by time, "
    "as if the years had no hold over her.\n";
    os << "Finally.. You have made it here.\n";
}

// Princess puzzle
void Princess::givePuzzle(std::istream& is, std::ostream& os) {
    char correctDecision = 'A';
    std::vector<std::string> multipleChoice = {"Use the potion", "Deny"};

    os << "Use the potion the witch gave you.\n";

    bool isCorrect = askMultipleChoice(is, os, multipleChoice, correctDecision);
    game->handleAnswerResult(isCorrect, os);

    if (isCorrect) {
        if (character->getInventory()->hasItem("Good Potion")) {
            character->getInventory()->useItem(os);
            wakeUp(os);
        } else if (character->getInventory()->hasItem("Bad Potion")) {
            character->getInventory()->useItem(os);
            os << "The princess died. You lose.\n";
            game->endGame();
        } else {
            os << "You don't have a potion! You lose.\n";
            game->endGame();
        }
    }
}

// Princess wake up
void Princess::wakeUp(std::ostream& os) {
    if (game) {
        os << "The princess opens her eyes and "
        "smiles. Congratulations. You Won!\n";
    }
}
