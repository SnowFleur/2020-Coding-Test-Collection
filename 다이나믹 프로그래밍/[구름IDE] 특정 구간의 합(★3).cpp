#include<iostream>
#include<vector>

int main() {
	std::vector<int> sum;
	std::vector<int> numbers;
	int N{}, left{}, right{};

	std::cin >> N;
	sum.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		int value{};
		std::cin >> value;
		numbers.emplace_back(value);

		if (i == 0)
			sum[i] = value;
		else
			sum[i] = sum[i - 1] + value;
	}

	std::cin >> left >> right;
	left -= 2;
	right -= 1;

	if (left < 0)
		std::cout << sum[right] << "\n";
	else
	std::cout << sum[right] - sum[left] << "\n";
}