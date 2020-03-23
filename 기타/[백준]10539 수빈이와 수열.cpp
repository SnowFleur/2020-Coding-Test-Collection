#include<iostream>
#include<array>

constexpr int MAX = 100;
// x= (이전 A의 수열들)- 몫*B값

int main() {
	std::array<int, MAX> list;
	int number;
	std::cin >> number;

	for (int i = 0; i < number; ++i)
		std::cin >> list[i];

	int divide = 1, a_sums=0;
	for (int i = 0; i < number; ++i) {
		std::cout << (divide * list[i])-a_sums  << " ";
		a_sums += (divide * list[i]) - a_sums;
		++divide;
	}
}