#include <gtest/gtest.h>
#include "../Lib/task.h"

TEST(TaskTest, DefaultConstructor) {
    Task task;

    EXPECT_GE(task.num_1, 1);
    EXPECT_LE(task.num_1, 10);

    EXPECT_GE(task.num_2, 1);
    EXPECT_LE(task.num_2, 10);

    EXPECT_TRUE(
        task.operation == '+' ||
        task.operation == '-' ||
        task.operation == '*'
    );

    if (task.operation == '+')
        EXPECT_EQ(task.answer, task.num_1 + task.num_2);
    else if (task.operation == '-')
        EXPECT_EQ(task.answer, task.num_1 - task.num_2);
    else if (task.operation == '*')
        EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}

TEST(TaskTest, ConstructorWithRange) {
    Task task(10, 20);

    EXPECT_GE(task.num_1, 10);
    EXPECT_LE(task.num_1, 20);

    EXPECT_GE(task.num_2, 10);
    EXPECT_LE(task.num_2, 20);
}

TEST(TaskTest, ConstructorWithPlus) {
    Task task(10, 20, '+');

    EXPECT_EQ(task.operation, '+');
    EXPECT_EQ(task.answer, task.num_1 + task.num_2);
}

TEST(TaskTest, ConstructorWithMinus) {
    Task task(10, 20, '-');

    EXPECT_EQ(task.operation, '-');
    EXPECT_EQ(task.answer, task.num_1 - task.num_2);
}

TEST(TaskTest, ConstructorWithMultiply) {
    Task task(10, 20, '*');

    EXPECT_EQ(task.operation, '*');
    EXPECT_EQ(task.answer, task.num_1 * task.num_2);
}
