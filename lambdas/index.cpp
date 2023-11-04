#include <iostream>
#include <array>
#include <string>

struct Student {
    std::string name;
    int points;
};

bool max_elem (int a, int b) {
    return a < b;
}

int main () {
    std::array<Student, 8> arr = { {
    { "Albert", 3 },
    { "Ben", 5},
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 }
    } };

    std::cout << std::max_element (arr.begin (), arr.end (), [](Student a, Student b) {return a.points < b.points;})->name << " is the best student.\n";

};
