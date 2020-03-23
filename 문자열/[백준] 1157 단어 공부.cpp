#include<iostream>
#include<string>
#include<array>
#include<algorithm>
constexpr int ALPHABET = 27;
int main() {
	std::array<int, ALPHABET> wordList{ 0 };
	std::string word;
	std::cin >> word;


	for (auto iter = word.cbegin(); iter != word.cend(); ++iter) {
		char temp = toupper(*iter);
		wordList[temp - 'A'] += 1;
	}

	int max = -1;
	int result = 0;

	for (int i = 0; i < ALPHABET; ++i) {
		if (wordList[i] > max) {
			max = wordList[i];
			result = i;
		}
	}
	auto same_count = std::count(wordList.cbegin(), wordList.cend(), max);

	if (same_count > 1)
		std::cout << "?\n";
	else
		std::cout << static_cast<char>(result + 'A') << "\n";
}