/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofia P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */
#include "Inventory.hpp"

#include <algorithm>

// Add an item to the inventory
void Inventory::addItem(std::shared_ptr<Item> item) {
  items.push_back(item);
}

// Check if an item exists in the inventory by name
bool Inventory::hasItem(const std::string& itemName) const {
  return std::any_of(items.begin(), items.end(),
              [&itemName](const std::shared_ptr<Item>& item) {
    return item->getName() == itemName;
  });
}

// Use an item from the inventory
void Inventory::useItem(std::ostream& os) {
  if (items.empty()) {
    os << "Inventory is empty. Nothing to use.\n";
    return;
  }

  os << "Using " << items.back()->getName() << "...\n";
  items.back()->useItem(os);
  items.pop_back();
}

// Check if inventory is empty
bool Inventory::isEmpty() const {
  return items.empty();
}
