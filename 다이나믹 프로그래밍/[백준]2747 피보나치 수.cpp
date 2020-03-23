#include<iostream>
constexpr int MAX = 45;
//동적 계획법으로 풀어보자

int main() {
	int number;
	int Fibonacci[MAX];
	Fibonacci[0] = 0;
	Fibonacci[1] = 1;
	std::cin >> number;

	for (int i = 2; i <= number; ++i) {
		Fibonacci[i]=Fibonacci[i - 2] + Fibonacci[i - 1];
	}
	std::cout << Fibonacci[number] << "\n";

}