#include<iostream>
constexpr int MAX_N           = 101;
constexpr int MAX_L           = 51;
constexpr int SUB_TASK1       = 100;
constexpr int SUB_TASK2       = 40;

/*
N: ������ ����
L: �������� ����
K: ��ȸ�߿� Ǯ �� �ִ� ������ �ִ� ����
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

	//Ǯ �� �ִ� �������� ������ ��� ������ hard ������ Ǯ �� �ֱ� ������ K��ŭ ���Ѵ�.
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