#include<iostream>

int main() {
    int N{}, count{};
    std::cin >> N;

    int left{}, right{}, total{};
    total = 1;
    left = 1;
    right = 2;

    while (left <= N) {

        total = total + right;

        //동일한 값이라면 count 증가
        if (total == N) {
            ++count;
            total = 0;
            ++left;
            right = left;
        }
        //total 값이 더 커졌으니 Left를 증가하고 다시시작
        else if (total > N) {
            ++left;
            total = 0;
            right = left;
        }
        else {
            ++right;
        }
    }
    std::cout << count << "\n";
}

