#include <sstream>
#include "gtest/gtest.h"
#include "Item.hpp"

// Test FlamingSword item
TEST(TestItem, FlamingSwordUse) {
    std::shared_ptr<Item> flamingSword;
    flamingSword = std::make_shared<FlamingSword>("Flaming Sword");


    std::stringstream ss;
    flamingSword->useItem(ss);

    EXPECT_EQ(ss.str(), "The Flaming Sword lights up the darkness!\n");
}

// Test GoodPotion item
TEST(TestItem, GoodPotionUse) {
    std::shared_ptr<Item> goodPotion;
    goodPotion = std::make_shared<GoodPotion>("Good Potion");

    std::stringstream ss;
    goodPotion->useItem(ss);

    EXPECT_EQ(ss.str(), "The Good Potion restores your vitality!\n");
}

// Test BadPotion item
TEST(TestItem, BadPotionUse) {
    std::shared_ptr<Item> badPotion = std::make_shared<BadPotion>("Bad Potion");

    std::stringstream ss;
    badPotion->useItem(ss);

    EXPECT_EQ(ss.str(), "The Bad Potion weakens you. Be careful!\n");
}
