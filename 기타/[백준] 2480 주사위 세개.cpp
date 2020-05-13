#include<iostream>
#include<set>
#include<array>
#include<algorithm>
int ThreeSameNumbers(int number) {
	return 10000 + number * 1000;
}

int TwoSameNumbers(int number) {
	return 1000 + number * 100;
}

int OtherNumbers(int number) {
	return number * 100;
}

int main() {
	std::set<int> set;
	std::array<int,3> dices;
	int result{};
	
	for (int i = 0; i < 3; ++i) {
		int value;
		std::cin >> value;
		dices[i] = value;
		set.insert(value);
	}
	std::sort(dices.begin(),dices.end(),std::less<int>());

	// 3개가 같은 숫자
	if (set.size() == 1) {
		result = ThreeSameNumbers(dices[0]);
	}
	// 2개가 같은 숫자
	else if (set.size() == 2) {
		result = TwoSameNumbers(dices[1]);
	}
	//1개가 같은 숫자
	else {
		result = OtherNumbers(dices[2]);
	}
	std::cout << result << "\n";
}