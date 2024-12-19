#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>

/**
 * @class Item Item.hpp
 * @brief Represents an item in the game.
 * @details This class serves as a base for various item types. It provides a method to get the name
 * @details of the item and a pure virtual function useItem() which must be implemented by derived
 * @details classes to define the specific behavior of using the item.
 */
class Item {
 public:
  /**
   * @brief Constructor for the Item class.
   * @param itemName The name of the item.
   */
  Item(const std::string& itemName);

  /**
   * @brief Destructor for the Item class.
   */
  virtual ~Item() = default;

  /**
   * @brief Gets the name of the item.
   * @return The name of the item as a string.
   */
  std::string getName() const;

  /**
   * @brief Use the item. This is a pure virtual function that must be implemented in derived classes.
   * @param os The output stream where information will be displayed.
   */
  virtual void useItem(std::ostream& os) = 0;

 private:
  /**
   * @brief String name of the item
   */
  std::string name;
};

/**
 * @class FlamingSword FlamingSword.hpp
 * @brief A derived class of Item representing a flaming sword.
 * @details This class defines the specific behavior of using the Flaming Sword in the game.
 */
class FlamingSword : public Item {
 public:
  /**
   * @brief Constructor for the FlamingSword class.
   * @param itemName The name of the item (defaults to "Flaming Sword").
   */
  FlamingSword(const std::string& itemName = "Flaming Sword");

  /**
   * @brief Use the Flaming Sword.
   * @details This method defines what happens when the Flaming Sword is used in the game.
   * @param os The output stream where information will be displayed.
   */
  void useItem(std::ostream& os) override;
};

/**
 * @class GoodPotion GoodPotion.hpp
 * @brief A derived class of Item representing a good potion.
 * @details This class defines the specific behavior of using a Good Potion in the game.
 */
class GoodPotion : public Item {
 public:
  /**
   * @brief Constructor for the GoodPotion class.
   * @param itemName The name of the item.
   */
  GoodPotion(const std::string& itemName);

  /**
   * @brief Use the Good Potion.
   * @details This method defines what happens when the Good Potion is used in the game.
   * @param os The output stream where information will be displayed.
   */
  void useItem(std::ostream& os) override;
};

/**
 * @class BadPotion BadPotion.hpp
 * @brief A derived class of Item representing a bad potion.
 * @details This class defines the specific behavior of using a Bad Potion in the game.
 */
class BadPotion : public Item {
 public:
  /**
   * @brief Constructor for the BadPotion class.
   * @param itemName The name of the item.
   */
  BadPotion(const std::string& itemName);

  /**
   * @brief Use the Bad Potion.
   * @details This method defines what happens when the Bad Potion is used in the game.
   * @param os The output stream where information will be displayed.
   */
  void useItem(std::ostream& os) override;
};

#endif
