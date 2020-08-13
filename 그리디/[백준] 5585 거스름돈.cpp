#include<iostream>

int main() {
    int money{};
    std::cin >> money;
    int change[6] = { 500,100,50,10,5,1 };
    int result{};

    //구매금액에서 빼기
    money = 1000 - money;

    for (int i = 0; i < 6; ++i) {

        //몫이 0이라면 나눌 수 없는 수
        if (money / change[i] == 0)
            continue;

        result+=(money / change[i]);
        money %= change[i];
    }
    std::cout << result << "\n";

}