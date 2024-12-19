#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Item.hpp"

/**
 * @class Inventory
 * @brief Represents an inventory that holds a collection of items.
 * @details This class manages a collection of items in the form of shared pointers. It allows adding items,
 * @details checking for the presence of an item, using an item, and checking if the inventory is empty.
 */
class Inventory {
 public:
  /**
   * @brief Adds an item to the inventory.
   * @param item A shared pointer to the item to be added to the inventory.
   */
  void addItem(std::shared_ptr<Item> item);

  /**
   * @brief Checks if an item with the given name exists in the inventory.
   * @param itemName The name of the item to search for.
   * @return True if the item is found, otherwise false.
   */
  bool hasItem(const std::string& itemName) const;

  /**
   * @brief Uses the first item in the inventory and outputs the result.
   * @details This method calls the `useItem()` function of the first item in the inventory and outputs the result
   * @details to the provided output stream.
   * @param os The output stream where information about the used item will be displayed.
   */
  void useItem(std::ostream& os);

  /**
   * @brief Checks if the inventory is empty.
   * @return True if the inventory has no items, otherwise false.
   */
  bool isEmpty() const;

 private:
  /**
   * @brief A vector storing shared pointers to the items in the inventory.
   */
  std::vector<std::shared_ptr<Item>> items;
};

#endif
