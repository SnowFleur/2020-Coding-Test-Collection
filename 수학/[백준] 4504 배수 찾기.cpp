#include<iostream>
int main() {
	int N{};
	int value = 1;
	std::cin >> N;

	while (true) {
		std::cin >> value;

		if (value == 0)
			break;
		if (value % N == 0)
			std::cout << value << " is a multiple of " << N << ".\n";
		else
			std::cout << value << " is NOT a multiple of " << N << ".\n";
	}
}