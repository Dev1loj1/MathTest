#include <iostream>
#include "../Lib/task.h"

int main() {
    int count;

    std::cout << "Enter number of questions: ";
    std::cin >> count;

    MathTest test(count, 1, 20);

    test.run();

    return 0;
}
