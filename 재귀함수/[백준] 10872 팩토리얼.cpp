#include<iostream>
int Recursive(int N) {
	if (N == 1 || N == 0)
		return 1;

	return N * Recursive(N - 1);
}
int main() {
	int N;
	std::cin >> N;
	std::cout << Recursive(N) << "\n";
}