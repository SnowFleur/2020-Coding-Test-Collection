#include<iostream>
#include<vector>

int main() {
    int N{}, K{};
    std::cin >> N >> K;

    std::vector<int>coins;

    for (int i = 0; i < N; ++i) {
        int coin{};
        std::cin >> coin;
        if (coin <= K) //K �̻��� ���ΰ��� �޾ƺ��� �ǹ̰� ����.
            coins.emplace_back(coin);
    }

    int minSumCount{}, sum{}; 
    auto iter = coins.rbegin(); 
    while (sum != K) {

        if (*iter + sum <= K) { //���� ��+sum�� K���� �۴ٸ� ����
            sum += *iter;
            minSumCount++;
        }
        else { //�ƴ϶�� ���� �ݺ��� �̵�
            ++iter;
        }
    }
    std::cout << minSumCount << "\n";
}