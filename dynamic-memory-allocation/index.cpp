#include <iostream>
#include <string>

int main () {
    std::cout << "How many names will you enter?\n Answer: ";
    std::size_t namesCount;
    std::cin >> namesCount;
    std::string* names (new std::string[namesCount]{});
    for (int i = 0; i < namesCount; ++i) {
        std::string currentName{ "" };
        std::cout << "Please enter next name: ";
        std::cin >> currentName;
        *(names + i) = currentName;
    }

    std::sort (names, (names + namesCount));
    for (int i = 0; i < namesCount; ++i) {
        std::cout << *(names + i) << ' ';
    }

    std::cout << '\n';

    delete[] names;
    return 0;
}
