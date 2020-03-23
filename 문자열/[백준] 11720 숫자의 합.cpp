#include<iostream>
#include<string>

int main() {
	std::string s{};
	unsigned long long integer{ 0 }, result{ 0 },n;
	std::cin >> n;
	std::cin >> s;
	
	for (auto i : s) {
		integer = i - '0';
		result += integer;
	}
	std::cout << result << "\n";

}