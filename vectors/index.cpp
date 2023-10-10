#include <vector>
#include <string>
#include <iostream>


int main()
{
    std::vector<std::string_view> names{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Enter a name: ";
    std::string userName{};
    std::cin >> userName;
    for(const auto& name : names){
        if(userName == name) {
            std::cout << name << " was found.\n";
            return 0;
        }
    }

    std::cout << userName << " was not found.\n";
    return 0;
}
