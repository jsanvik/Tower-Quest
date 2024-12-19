#include <memory>
#include <sstream>
#include "gtest/gtest.h"
#include "Inventory.hpp"
#include "Item.hpp"

// Test fixture for Inventory class
class TestInventory : public ::testing::Test {
 protected:
    void SetUp() override {
        inventory = std::make_shared<Inventory>();
        flamingSword = std::make_shared<FlamingSword>("Flaming Sword");
        goodPotion = std::make_shared<GoodPotion>("Good Potion");
        badPotion = std::make_shared<BadPotion>("Bad Potion");
    }

    std::shared_ptr<Inventory> inventory;
    std::shared_ptr<FlamingSword> flamingSword;
    std::shared_ptr<GoodPotion> goodPotion;
    std::shared_ptr<BadPotion> badPotion;
};

// Test addItem and hasItem
TEST_F(TestInventory, AddItemAndHasItem) {
    inventory->addItem(flamingSword);
    EXPECT_TRUE(inventory->hasItem("Flaming Sword"));
    EXPECT_FALSE(inventory->hasItem("Nonexistent Item"));
}

// Test useItem
TEST_F(TestInventory, UseItem) {
    inventory->addItem(flamingSword);

    std::stringstream ss;
    inventory->useItem(ss);


    EXPECT_EQ(ss.str(), "Using Flaming Sword...\n"
    "The Flaming Sword lights up the darkness!\n");

    EXPECT_FALSE(inventory->hasItem("Flaming Sword"));
}

// Test isEmpty method
TEST_F(TestInventory, IsEmpty) {
    EXPECT_TRUE(inventory->isEmpty());

    inventory->addItem(flamingSword);
    EXPECT_FALSE(inventory->isEmpty());

    inventory->useItem(std::cout);
    EXPECT_TRUE(inventory->isEmpty());
}

// Test hasItem with multiple items
TEST_F(TestInventory, HasMultipleItems) {
    inventory->addItem(flamingSword);
    inventory->addItem(goodPotion);

    EXPECT_TRUE(inventory->hasItem("Flaming Sword"));
    EXPECT_TRUE(inventory->hasItem("Good Potion"));
    EXPECT_FALSE(inventory->hasItem("Bad Potion"));
}

// Test useItem when inventory is empty
TEST_F(TestInventory, UseItemWhenEmpty) {
    std::stringstream ss;
    inventory->useItem(ss);

    EXPECT_EQ(ss.str(), "Inventory is empty. Nothing to use.\n");


    EXPECT_TRUE(inventory->isEmpty());
}
