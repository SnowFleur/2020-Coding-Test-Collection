#include<iostream>

int main() {
    int money{};
    std::cin >> money;
    int change[6] = { 500,100,50,10,5,1 };
    int result{};

    //���űݾ׿��� ����
    money = 1000 - money;

    for (int i = 0; i < 6; ++i) {

        //���� 0�̶�� ���� �� ���� ��
        if (money / change[i] == 0)
            continue;

        result+=(money / change[i]);
        money %= change[i];
    }
    std::cout << result << "\n";

}