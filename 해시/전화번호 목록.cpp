#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (auto i = phone_book.begin(); i != phone_book.end()-1; ++i) {
			std::string toWord = *i;
			std::string fromWord = *(i + 1);

			//1. 사이즈 만큼 자르자
			if (toWord.size() < fromWord.size()) {
				fromWord=fromWord.substr(0, toWord.size());
			}

			else {
				toWord=toWord.substr(0, fromWord.size());
			}

			if (fromWord == toWord) {
				answer = false;
				break;
			}
	}
	return answer;
}


int main() {
	
	std::vector<string> v{ "119,","97674223","1195524421" };
   //std::vector<string> v{ "123,","456","789" };
	//std::vector<string> v{ "1192456","119" };
	std::cout << std::boolalpha << solution(std::move(v)) << std::endl;




}