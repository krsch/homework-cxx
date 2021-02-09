#include "rearrange.hpp"
#include <iostream>
#include <sstream>
#include <string>

void print (std::vector<int> const &input) {
    for(auto element : input) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::istringstream ss(s);

    std::vector<int> input;
    int i;
    while (ss >> i)
        input.emplace_back(i);
    auto rearranged_array = rearrange(input);
    print(rearranged_array);

    // массив 2n элементов
    // [0, 1, .., n-1], [n, n+1, .., 2n-2, 2n-1]
    // преобразовать в массив
    // 0, n, 1, n+1, .., n-1, 2n-1


    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    // 1, 6, 2, 7, 3, 8, 4, 9, 5, 10}); }


    // *реорганизовать, не создавая новый массив
}