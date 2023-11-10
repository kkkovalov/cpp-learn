#include <vector>
#include <string>
#include <iostream>

template <typename T, typename U>
bool isValueInArray(const std::vector<T> &names, U c_name){
    for(const auto& name : names){
        if(c_name == name) {
            return true;
        }
    }
    return false;
};

int main()
{
    std::vector<std::string_view> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string userName{};
    std::cin >> userName;
    std::cout << userName << isValueInArray(names, userName) ? " was found.\n" : " was not found.\n";
    return 0;
}
