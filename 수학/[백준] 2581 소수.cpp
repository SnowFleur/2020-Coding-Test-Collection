#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
constexpr int DELETE_NUMBER = 0;

std::vector<int> g_v;

// M: min N: max
void PrimeNumber(int M, int N) {
	int sum_number{}, min_number{};

	g_v.assign(N + 1, DELETE_NUMBER);
	for (int i = M; i <= N; ++i)
		g_v[i] = i;

	//���� 1�� �ִٸ� 1�� ������
	if (g_v[1] == 1)
		g_v[1] = DELETE_NUMBER;


	//�����佺�׳׽��� ü �� ����� ����
	for (int i = 2; i <= N; ++i) {

		for (int j = i + 1; j <= N; ++j) {

			if (j % i == 0) {
				if (g_v[j] != DELETE_NUMBER) {
					g_v[j] = DELETE_NUMBER;
				}
			}
		}
	
	}


	sum_number = std::accumulate(g_v.begin(), g_v.end(), 0);
	min_number = *(std::min_element(g_v.begin(), g_v.end(), [](const auto& lhs, const auto& rhs) {
		if (lhs != DELETE_NUMBER && rhs != DELETE_NUMBER)
			return lhs < rhs;

		if (lhs == DELETE_NUMBER)
			return false;
		else
			return true;

	}));
	if (min_number == 0) {
		std::cout << -1 << "\n";
	}
	else {
		std::cout << sum_number << "\n";
		std::cout << min_number << "\n";
	}

}


int main() {
	int M{}, N{};
	std::cin >> M >> N;
	PrimeNumber(M, N);

}