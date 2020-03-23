#include<iostream>
#include <vector>
using namespace std;

void Recursive(int value, int index, vector<int>& numbers);
int g_answer, g_target;

int solution(vector<int> numbers, int target) {
	g_target = target;
	Recursive(0, 0, numbers);
	return g_answer;
}
void Recursive(int value, int index, vector<int>& numbers) {
	if (index == numbers.size()) {
		if (value == g_target) {
			++g_answer;
		}
			return;
	}

	Recursive(value - numbers[index], index + 1, numbers);
	Recursive(value + numbers[index], index + 1, numbers);
}
