#include<iostream>
#include<vector>
constexpr int MAX_N = 101;
constexpr int MAX_M = 300001;



int BS(int N, int M, std::vector<int>& v) {
	int result{};

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {

				int total_sum = v[i] + v[j] + v[k];

				//M���� 3���� ī������ ������ 
				if (M >= total_sum) {
					//�� ���� ã�� ������ ũ�ٸ� �ٲ۴�.
					if (result < total_sum)
						result = total_sum;
				}
			}
		}
	}

	return result;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> v;

	int value{};
	for (int i = 0; i < N; ++i) {
		std::cin >> value;
		v.emplace_back(value);
	}

	std::cout << BS(N, M, v) << "\n";
}