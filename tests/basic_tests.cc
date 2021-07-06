#include <gtest/gtest.h>
#include "CircleElement.hpp"
#include "GenerateRandomNumbers.hpp"
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) 
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(HelloTest, CircleElementTesting) 
{
  CircleElement c;
  EXPECT_EQ(10.0, c.getRad());

  unsigned int temp = RandomNumbers::generate(10,100);
  EXPECT_EQ(true, (temp > 10 && temp < 100)) << "Number not in the range !";
}

TEST(AnotherHelloTest, CircleELementTesting2)
{
  CircleElement c;
  c.setPos(2.2, 4.4);
  // EXPECT_EQ({2.2, 4.4}, c.getPos()); //<< "Circle position is not the one that has been set !";
}