#include <vector>
#include <iostream>

template <typename T>
void printElement(const std::vector<T> &v, const std::size_t index){
    if(index >= v.size()) std::cout << "Invalid index";
    else {
        std::cout << "The element has value: " << v[index] << '\n';
    }
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
