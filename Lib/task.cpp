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
// ==================== RUN ====================

void MathTest::run() {
    correct_count = 0;

    std::cout << "===== MATH TEST =====" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout
            << i + 1 << ") "
            << tasks[i].num_1 << " "
            << tasks[i].operation << " "
            << tasks[i].num_2
            << " = ";

        int answer;
        std::cin >> answer;

        set_user_answer(i, answer);
    }

    std::cout << std::endl;

    show_statistics();
}


// ==================== ОЦЕНКА ====================

char MathTest::get_mark() const {
    if (count == 0) {
        return 'F';
    }

    double percent =
        static_cast<double>(correct_count) / count * 100;

    if (percent >= 90)
        return 'A';

    if (percent >= 75)
        return 'B';

    if (percent >= 60)
        return 'C';

    if (percent >= 50)
        return 'D';

    return 'F';
}


// ==================== СТАТИСТИКА ====================

void MathTest::show_statistics() const {
    const int width = 10;

    // Номера
    std::cout << "|"
              << std::setw(width) << "No";

    for (int i = 0; i < count; i++) {
        std::cout << " |"
                  << std::setw(width - 1)
                  << i + 1;
    }

    std::cout << " |" << std::endl;


    // Разделитель
    std::cout << "+";

    for (int i = 0; i < (count + 1) * (width + 1); i++) {
        std::cout << "-";
    }

    std::cout << "+" << std::endl;


    // Questions
    std::cout << "|"
              << std::setw(width)
              << "Question";

    for (int i = 0; i < count; i++) {
        std::cout << " | "
                  << tasks[i].num_1
                  << " "
                  << tasks[i].operation
                  << " "
                  << tasks[i].num_2;

        int question_length = 5;

        std::cout << std::setw(
            width - question_length - 1
        ) << "";
    }

    std::cout << " |" << std::endl;


    // Правильные ответы
    std::cout << "|"
              << std::setw(width)
              << "True Answer";

    for (int i = 0; i < count; i++) {
        std::cout << " |"
                  << std::setw(width - 1)
                  << tasks[i].answer;
    }

    std::cout << " |" << std::endl;


    // Ответы пользователя
    std::cout << "|"
              << std::setw(width)
              << "Your Answer";

    for (int i = 0; i < count; i++) {
        std::cout << " |"
                  << std::setw(width - 1)
                  << user_answers[i];
    }

    std::cout << " |" << std::endl;


    // Результаты
    std::cout << "|"
              << std::setw(width)
              << "Result";

    for (int i = 0; i < count; i++) {

        char result;

        if (user_answers[i] == tasks[i].answer)
            result = '+';
        else
            result = '-';

        std::cout << " |"
                  << std::setw(width - 1)
                  << result;
    }

    std::cout << " |" << std::endl;


    std::cout << std::endl;

    std::cout
        << "Total Result: "
        << correct_count
        << " / "
        << count
        << " (mark: "
        << get_mark()
        << ")"
        << std::endl;
}


// ==================== GETTERS ====================

int MathTest::get_count() const {
    return count;
}


int MathTest::get_correct_count() const {
    return correct_count;
}


Task MathTest::get_task(int index) const {
    return tasks[index];
}


int MathTest::get_user_answer(int index) const {
    return user_answers[index];
}