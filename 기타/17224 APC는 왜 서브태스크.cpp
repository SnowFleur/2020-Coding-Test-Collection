#include<iostream>
constexpr int MAX_N           = 101;
constexpr int MAX_L           = 51;
constexpr int SUB_TASK1       = 100;
constexpr int SUB_TASK2       = 40;

/*
N: 문제의 개수
L: 현정이의 역량
K: 대회중에 풀 수 있는 문제의 최대 개수
*/
int main() {
	int N, L, K, SUB1, SUB2;
	int easy_count{}, hard_count{};
	std::cin >> N >> L >> K;

	for (int i = 0; i < N; ++i) {
		std::cin >> SUB1 >> SUB2;
		if (L >= SUB2)
			++hard_count;
		else {
			if (L >= SUB1)
				++easy_count;
		}
	}

	//풀 수 있는 개수보다 많으면 모든 문제를 hard 문제를 풀 수 있기 때문에 K만큼 곱한다.
	int score{};
	if (hard_count > K) {
		score = K * (SUB_TASK1 + SUB_TASK2);
	}

	else {
		score += hard_count * (SUB_TASK1 + SUB_TASK2);
		K -= hard_count;
		if (easy_count > K) {
			score += K * SUB_TASK1;
		}
		else
			score += easy_count * SUB_TASK1;
	}

	std::cout << score << "\n";
}