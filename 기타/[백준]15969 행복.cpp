#include<iostream>
#include<array>
#include<algorithm>

constexpr int MAX = 1000;

int main() {
	std::array<int, MAX> list;
	int count;

	std::cin >> count;

	for (int i = 0; i < count; ++i)
		std::cin >> list[i];

	auto max_iter = std::max_element(list.begin(), list.begin() + count);
	auto min_iter = std::min_element(list.begin(), list.begin() + count);

	std::cout << (*max_iter) - (*min_iter) << "\n";

}

