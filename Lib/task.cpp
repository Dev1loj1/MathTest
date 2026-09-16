#include "task.h"
#include <cstdlib>

Task::Task() {
    num_1 = rand() % 10 + 1;
    num_2 = rand() % 10 + 1;

    int op = rand() % 3;

    if (op == 0)
        operation = '+';
    else if (op == 1)
        operation = '-';
    else
        operation = '*';

    if (operation == '+')
        answer = num_1 + num_2;
    else if (operation == '-')
        answer = num_1 - num_2;
    else
        answer = num_1 * num_2;
}

Task::Task(int min, int max, char operation) {
    num_1 = rand() % (max - min + 1) + min;
    num_2 = rand() % (max - min + 1) + min;

    if (operation == '\0') {
        int op = rand() % 3;

        if (op == 0)
            this->operation = '+';
        else if (op == 1)
            this->operation = '-';
        else
            this->operation = '*';
    }
    else {
        this->operation = operation;
    }

    if (this->operation == '+')
        answer = num_1 + num_2;
    else if (this->operation == '-')
        answer = num_1 - num_2;
    else
        answer = num_1 * num_2;
}