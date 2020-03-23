#include<iostream>
#include<string>
#include<algorithm>
#include<string_view>

constexpr int MAX_N				= 10001;
std::string_view RIGHT_ANSWER	= "O";
std::string_view WRONG_ANWER	= "X";

int main() {
	int bonus_score{};
	int total_score{};
	int N{};
	std::string S;

	std::cin >> N;
	std::cin >> S;

	for (int i = 0; i < S.size(); ++i)
		S[i] = std::toupper(S[i]);

	for (int i = 0; i < N; ++i) {

		if (S[i] == *(RIGHT_ANSWER.data())) {
			total_score += (i + 1) + bonus_score++;
		}
		else
			bonus_score = 0;
	}
	std::cout << total_score << "\n";
}