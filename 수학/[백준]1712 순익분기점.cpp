#include<iostream>
using llong_t = unsigned long long;
llong_t MAX = 2100000000;
llong_t A, B, C;

int main() {
	std::cin >> A >> B >> C;
	llong_t result = A / (C - B) + 1;

	if (B >=C)
		std::cout << "-1";
	else if (result > 0)
		std::cout << result;
	else
		std::cout << "-1";

}