#include<iostream>
#include<array>
constexpr int HERO_NUMBER = 87;

int main() {
	std::array<bool, HERO_NUMBER>select_array{false};
	int select_number;
	//team_select
	for (int i = 0; i < 4; ++i) {
		std::cin >> select_number;
		select_array[select_number] = true;
	}

	//my_select
	int count{};
	for (int i = 0; i < 5; ++i) {
		std::cin >> select_number;
		if (select_array[select_number]==false) {
			++count;
		}
	}
	std::cout<<count<<"\n";
}