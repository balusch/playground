#include <gtest/gtest.h>

#include "view01.h"

TEST(SmokeTest, Basic) {
  EXPECT_EQ(make_greeting("cpp"), "hello, cpp!");
}
