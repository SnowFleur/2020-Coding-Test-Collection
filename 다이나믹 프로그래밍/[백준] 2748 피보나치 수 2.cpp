#include<iostream>
constexpr int MAX = 91;
int main() {
	int n = 0;
	long long Fibonacci[MAX];
	std::cin >> n;
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;

	for (int i = 2; i <= n; ++i) {
		Fibonacci[i] = Fibonacci[i - 2] + Fibonacci[i - 1];
	}
	std::cout << Fibonacci[n] << "\n";
}