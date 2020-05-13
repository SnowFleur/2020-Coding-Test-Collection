#include<iostream>

constexpr int MAX_N		= 1000;
constexpr int SK		= 0;
constexpr int CY		= 1;

int main() {
	int N;
	std::cin >> N;

	int player = SK;
	while (N > 0) {

		if (N / 3 == 0) {
			--N;
		}
		else {
			N -= 3;
		}
		player = 1 - player;
	}

	if (player)
		std::cout << "SK" << "\n";
	else
		std::cout << "CY" << "\n";
}