#include <iostream>
#include <utility>

template <typename T, typename U>
struct Pair
{
    T first{};
    U second{};
};

// CTAD - Class template Argument deduction guide.
template <typename T, typename U>
Pair(T,U) -> Pair<T,U>;

template <typename T, typename U>
void print(std::pair<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main()
{
    Pair<int, int> p1{5, 6};
    std::cout << p1.first << ' ' << p1.second << '\n';
    Pair<double, double> p2{5.2, 6.1};
    std::cout << p2.first << ' ' << p2.second << '\n';
    std::pair<int, int> p3{1, 2};
    print(p3);
    std::pair<double, double> p4{3.123, 8.12};
    print(p4);
}
