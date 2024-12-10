#include <rational/rational.h>
#include <iostream>

bool test() {
    Rational a;
    std::cin >> a;
    if (std::cin.good()) {
        std::cout << "Correct: " << a << '\n';
        //a += 10;
        Rational b;
        std::cin >> b;
        if (std::cin.good()) {
            a += b;
            std::cout << a << " " << b << '\n';
            b += 10;
            std::cout << a << " " << b << '\n';
            a = a + b;
            std::cout << a << " " << b << '\n';
            return true;
        }
    }
    std::cout << "Incorrect\n";
    return false;
}
signed main() {
    for (int i = 0; i < 5; ++i)
        test();
    return 0;
}
