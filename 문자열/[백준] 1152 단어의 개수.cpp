#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<sstream>

int main() {
	std::string s;
	std::getline(std::cin, s);

	std::istringstream text(s);
	std::istream_iterator <std::string> begin(text);
	std::istream_iterator<std::string>end;

	int result{};
	for (auto i = begin; i != end; ++i)
		++result;

	std::cout << result << "\n";

}