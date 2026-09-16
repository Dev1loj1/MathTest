#include "task.h"

#include <iostream>
#include <cstdlib>
#include <iomanip>


// ==================== TASK ====================

Task::Task() {
    num_1 = rand() % 10 + 1;
    num_2 = rand() % 10 + 1;

    int op = rand() % 4;

    if (op == 0)
        operation = '+';
    else if (op == 1)
        operation = '-';
    else if (op == 2)
        operation = '*';
    else
        operation = '/';

    if (operation == '+') {
        answer = num_1 + num_2;
    }
    else if (operation == '-') {
        answer = num_1 - num_2;
    }
    else if (operation == '*') {
        answer = num_1 * num_2;
    }
    else {
        // Чтобы деление всегда было целочисленным
        answer = num_1;
        num_1 = num_1 * num_2;
    }
}


Task::Task(int min, int max, char operation) {
    num_1 = rand() % (max - min + 1) + min;
    num_2 = rand() % (max - min + 1) + min;

    if (operation == '\0') {
        int op = rand() % 4;

        if (op == 0)
            this->operation = '+';
        else if (op == 1)
            this->operation = '-';
        else if (op == 2)
            this->operation = '*';
        else
            this->operation = '/';
    }
    else {
        this->operation = operation;
    }

    if (this->operation == '+') {
        answer = num_1 + num_2;
    }
    else if (this->operation == '-') {
        answer = num_1 - num_2;
    }
    else if (this->operation == '*') {
        answer = num_1 * num_2;
    }
    else if (this->operation == '/') {
        // Переделываем пример так, чтобы ответ был целым
        answer = num_1;
        num_1 = num_1 * num_2;
    }
}


// ==================== MATHTEST ====================

// Конструктор только по количеству вопросов
MathTest::MathTest(int count) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        user_answers[i] = 0;
    }
}


// Конструктор: количество + диапазон
MathTest::MathTest(int count, int min, int max) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        tasks[i] = Task(min, max);
        user_answers[i] = 0;
    }
}


// Конструктор: количество + диапазон + операция
MathTest::MathTest(int count, int min, int max, char operation) {
    this->count = count;
    correct_count = 0;

    tasks = new Task[count];
    user_answers = new int[count];

    for (int i = 0; i < count; i++) {
        tasks[i] = Task(min, max, operation);
        user_answers[i] = 0;
    }
}


// Деструктор
MathTest::~MathTest() {
    delete[] tasks;
    delete[] user_answers;
}

// ==================== ОБРАБОТКА ОТВЕТА ====================

void MathTest::set_user_answer(int index, int answer) {
    if (index < 0 || index >= count) {
        return;
    }

    user_answers[index] = answer;

    if (answer == tasks[index].answer) {
        correct_count++;
    }
}