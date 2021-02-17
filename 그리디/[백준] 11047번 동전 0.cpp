#include<iostream>
#include<vector>

int main() {
    int N{}, K{};
    std::cin >> N >> K;

    std::vector<int>coins;

    for (int i = 0; i < N; ++i) {
        int coin{};
        std::cin >> coin;
        if (coin <= K) //K 이상의 코인값은 받아봐야 의미가 없다.
            coins.emplace_back(coin);
    }

    int minSumCount{}, sum{}; 
    auto iter = coins.rbegin(); 
    while (sum != K) {

        if (*iter + sum <= K) { //현재 값+sum이 K보다 작다면 덧셈
            sum += *iter;
            minSumCount++;
        }
        else { //아니라면 코인 반복자 이동
            ++iter;
        }
    }
    std::cout << minSumCount << "\n";
}