/**
 * @author Solomon H <solomon.haile@uleth.ca>, Sofiah P <s.plarisan@uleth.ca>,
 * @author John A <j.anvik@uleth.ca>, Gurmannat DS <sandhug@uleth.ca>
 * @date Fall 2024
 */

#include "Character.hpp"
#include "gtest/gtest.h"

TEST(TestCharacter, constructorTest) {
  Character latifa("Queen Latifa");
  EXPECT_EQ(latifa.getName(), "Queen Latifa");
  EXPECT_EQ(latifa.hasItem("Your Wallet"), false);
}
