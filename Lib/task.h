

#ifndef MATHTEST_TASK_H
#define MATHTEST_TASK_H
#pragma once

struct Task {
    int num_1;
    int num_2;
    char operation;
    int answer;

    Task();
    Task(int min, int max, char operation = '\0');
};

class MathTest {
private:
    Task* tasks;
    int count;

    int* user_answers;
    int correct_count;

public:
    MathTest(int count);
    MathTest(int count, int min, int max);
    MathTest(int count, int min, int max, char operation);

    ~MathTest();

    void run();
    void show_statistics() const;

    // Отдельный метод обработки ответа.
    // Удобен в том числе для GoogleTest.
    void set_user_answer(int index, int answer);

    // Геттеры для тестирования
    int get_count() const;
    int get_correct_count() const;
    Task get_task(int index) const;
    int get_user_answer(int index) const;

    char get_mark() const;
};
#endif //MATHTEST_TASK_H
