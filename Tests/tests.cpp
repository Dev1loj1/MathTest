#include <gtest/gtest.h>
#include "../Lib/task.h"

TEST(TaskTest, ConstructorWithRange) {
    Task task(10, 20);

    EXPECT_GE(task.num_1, 10);
    EXPECT_LE(task.num_1, 20);

    EXPECT_GE(task.num_2, 10);
    EXPECT_LE(task.num_2, 20);
}
