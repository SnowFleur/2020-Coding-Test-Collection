#include<iostream>
#include<vector>
std::vector<int>v;
int g_count;

void GetPrimeNumber(int n);
int main() {

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int number;
		std::cin >> number;
		v.emplace_back(number);
	}

	for (auto i : v)
		GetPrimeNumber(i);

	std::cout << g_count;
}

void GetPrimeNumber(int n) {
	if (n < 2)
		return;

	else if (n == 2) {
		++g_count;
		return;
	}

	for (int i = 2; i < n; ++i) {
		if (n % i == 0)
			return;
	}
	++g_count;

}
