#include <gtest/gtest.h>
#include "../Lib/task.h"


TEST(MathTestTest, ConstructorWithCount) {
    MathTest test(5);

    EXPECT_EQ(test.get_count(), 5);
    EXPECT_EQ(test.get_correct_count(), 0);
}


TEST(MathTestTest, ConstructorWithRange) {
    MathTest test(10, 5, 15);

    EXPECT_EQ(test.get_count(), 10);

    for (int i = 0; i < test.get_count(); i++) {
        Task task = test.get_task(i);

        EXPECT_GE(task.num_1, 5);
        EXPECT_LE(task.num_1, 15);

        EXPECT_GE(task.num_2, 5);
        EXPECT_LE(task.num_2, 15);
    }
}


TEST(MathTestTest, ConstructorWithOperation) {
    MathTest test(10, 1, 20, '+');

    for (int i = 0; i < test.get_count(); i++) {
        Task task = test.get_task(i);

        EXPECT_EQ(task.operation, '+');
        EXPECT_EQ(task.answer, task.num_1 + task.num_2);
    }
}


TEST(MathTestTest, CorrectAnswer) {
    MathTest test(1, 1, 10, '+');

    Task task = test.get_task(0);

    test.set_user_answer(0, task.answer);

    EXPECT_EQ(test.get_user_answer(0), task.answer);
    EXPECT_EQ(test.get_correct_count(), 1);
}


TEST(MathTestTest, WrongAnswer) {
    MathTest test(1, 1, 10, '+');

    Task task = test.get_task(0);

    test.set_user_answer(0, task.answer + 1);

    EXPECT_EQ(test.get_correct_count(), 0);
}


TEST(MathTestTest, SeveralAnswers) {
    MathTest test(3, 1, 10, '+');

    Task task0 = test.get_task(0);
    Task task1 = test.get_task(1);
    Task task2 = test.get_task(2);

    test.set_user_answer(0, task0.answer);
    test.set_user_answer(1, task1.answer + 1);
    test.set_user_answer(2, task2.answer);

    EXPECT_EQ(test.get_correct_count(), 2);
}
