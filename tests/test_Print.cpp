#include "Print.h"

#include <string>

#include <gtest/gtest.h>

static char output[1024];
static size_t length;

class PrintWrapper : public Print {
private:
public:
  size_t write(uint8_t byte) override {
    size_t n = 0;
    if (length < sizeof output - 1) {
      output[length++] = byte;
      output[length] = '\0';
      n = 1;
    } else {
      setWriteError();
    }
    return n;
  }
};

static class PrintWrapper output_;

// The fixture for testing class Foo.
class PrintTest : public testing::Test {

protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  PrintTest() {

    // You can do set-up work for each test here.
  }

  ~PrintTest() override {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
    // Code here will be called immediately after the constructor (right
    // before each test).
    length = 0;
  }

  void TearDown() override {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

TEST_F(PrintTest, dec_print_unsigned) {
  const size_t written = output_.print(123, DEC);
  EXPECT_EQ(written, 3);
  EXPECT_EQ(length, 3);
  EXPECT_STREQ(output, "123");
}

TEST_F(PrintTest, hex_print_unsigned) {
  const size_t written = output_.print(123, HEX);
  EXPECT_EQ(written, 2);
  EXPECT_EQ(length, 2);
  EXPECT_STREQ(output, "7B");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
