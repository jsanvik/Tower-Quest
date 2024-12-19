/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include "Character.hpp"

Character::Character(const std::string& name) : _name(name) {
  _inventory = new Inventory();
}

std::string Character::getName() const { return _name; }

Inventory* Character::getInventory() { return _inventory; }

bool Character::hasItem(std::string item) { return _inventory->hasItem(item); }

Character::Character() : _inventory(new Inventory()) {}
Character::~Character() { delete _inventory; }
