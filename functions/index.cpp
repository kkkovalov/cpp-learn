#include <iostream>
#include <functional>

int getInteger () {
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;
    return x;
};
char getUserOperator () {
    char op{};

    do {
        std::cout << "Choose an operation, available ('+', '-', '*', '/'): ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
};

int add (int a, int b) {
    return a + b;
};

int subtract (int a, int b) {
    return a - b;
};

int multiply (int a, int b) {
    return a * b;
};

int divide (int a, int b) {
    return a / b;
};

using ArithemticFunction = std::function<int (int, int)>;

ArithemticFunction getArithemticFunction (char op) {
    switch (op)
    {
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &divide;
    };

    return nullptr;
};

int main () {

    std::cout << "Welcome to the calculator!\n";
    int fInteger{ getInteger () };
    char op{ getUserOperator () };
    int sInteger{ getInteger () };

    ArithemticFunction fcn{ getArithemticFunction (op) };
    if (fcn) {
        std::cout << "Result of operation: " << fcn (fInteger, sInteger) << '\n';
    }
    return 0;
}
