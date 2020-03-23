#include<iostream>
#include<string>
#include<array>
constexpr int ALPHABET_LENGTH = 26;

int main() {
	std::string s;
	std::cin >> s;
	std::array<int, ALPHABET_LENGTH> alphabet_list;
	alphabet_list.fill(-1);

	for (auto i = s.cbegin(); i != s.cend(); ++i) {
		int index = *i - 'a';
		if (alphabet_list[index] == -1)
			alphabet_list[index] = i - s.begin();
	}
	for (auto i : alphabet_list)
		std::cout << i << " ";

}