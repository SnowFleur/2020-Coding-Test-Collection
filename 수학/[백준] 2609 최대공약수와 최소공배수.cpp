#include<iostream>

int GCD(int lhs, int rhs) {
    //lhs¿¡ Å«°ª
    if (rhs > lhs) {
        std::swap<int>(rhs, lhs);
    }
    
    while (rhs != 0) {
        int n = lhs % rhs;
        lhs = rhs;
        rhs = n;
    }
    return lhs;
}

int LCM(int lhs, int rhs) {
    return lhs*rhs / GCD(lhs, rhs);
}

int main() {
    int lhs{}, rhs{};
    std::cin >> lhs>>rhs;


    std::cout << GCD(lhs, rhs) << "\n";
    std::cout << LCM(lhs, rhs) << "\n";

}