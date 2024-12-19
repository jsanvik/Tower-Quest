/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include "Item.hpp"

// Item base class constructor
Item::Item(const std::string& itemName) : name(itemName) {}

std::string Item::getName() const {
  return name;
}

// FlamingSword implementation
FlamingSword::FlamingSword(const std::string& itemName) : Item(itemName) {}

void FlamingSword::useItem(std::ostream& os) {
  os << "The Flaming Sword lights up the darkness!\n";
}

// GoodPotion implementation
GoodPotion::GoodPotion(const std::string& itemName) : Item(itemName) {}

void GoodPotion::useItem(std::ostream& os) {
  os << "The Good Potion restores your vitality!\n";
}

// BadPotion implementation
BadPotion::BadPotion(const std::string& itemName) : Item(itemName) {}

void BadPotion::useItem(std::ostream& os) {
  os << "The Bad Potion weakens you. Be careful!\n";
}
