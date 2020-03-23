#include<iostream>
#include<string>
#include<vector>
using words = std::pair<int, std::string>;
int main() {
	int count;
	std::cin >> count;
	std::vector<words>vector;

	for (int i = 0; i < count; ++i) {
		words word;
		std::cin >> word.first >> word.second;
		vector.emplace_back(word);
	}


	for (auto iter : vector) {
		int index = 0;
		std::string answer;
		size_t length = iter.second.length();
		for (int i = 0; i < iter.first * length; ++i) {

			if (i != 0 && (i % iter.first == 0)) {
				index++;
			}
			answer += iter.second[index];
		}
		std::cout << answer << "\n";
	}


}