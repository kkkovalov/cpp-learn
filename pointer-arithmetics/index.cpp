#include <iostream>
#include <string>

int main () {

    constexpr char str[]{ "Hello, world!" };
    auto begin = str;
    auto end = str + std::size (str) - 2;
    for (; begin - 1 != end; --end) {
        auto e = *end;
        std::cout << e << '\n';
    };
    return 0;
}
