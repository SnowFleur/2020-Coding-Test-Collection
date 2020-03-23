#include<iostream>
#include<string>
#include<algorithm>
int main() {
	std::string s1{}, s2{};

	std::cin >> s1 >> s2;
	std::reverse(s1.begin(), s1.end());
	std::reverse(s2.begin(), s2.end());
	
	if (s1 > s2) {
		std::cout << s1 << "\n";
	}
	else
		std::cout << s2 << "\n";

}