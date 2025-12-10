//
// Created by Yaroslava Krenevych on 20.11.2025.
//

#include <iostream>


namespace MAX_SPACE {
    template <typename T>
    T max(T a, T b) {
        return a > b ? a : b;
    }

    template <>
    std::string max(std::string a, std:: string b) {
        return a.length() > b.length() ? a : b;
    }
}

int main() {
    int x = MAX_SPACE::max(1, 3);
    std::cout << x << std::endl;
    double y = MAX_SPACE::max<double>(1.3, 8.2f);
    std::cout << y << std::endl;
    std::cout << std::max(1.3, 8.2) << std::endl;

    std::cout << MAX_SPACE::max("1asd", "2133") << " "<<
            MAX_SPACE::max(std::string("1asd"), std::string("2133")) <<
                std::endl;

    return 0;
}
