/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */

#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>

#include "Inventory.hpp"

class Character {
 public:
  /**
   * @brief Character constructor takes a name parameter.
   * @param name Name of the character.
   */
  Character(const std::string& name);
  /**
   * @brief Returns name of character.
   */
  std::string getName() const;
  /**
   * @brief Returns a pointer to the character's inventory.
   */
  Inventory* getInventory();

  /**
   * @brief Returns true if the character has an item with a given name.
   * @param item String of the name of the item.
   */
  bool hasItem(std::string item);
  /**
   * @brief default constructor.
   */
  Character();
  /**
   * @brief destructor
   */
  ~Character();

 private:
  std::string _name;
  Inventory* _inventory;
};

#endif
