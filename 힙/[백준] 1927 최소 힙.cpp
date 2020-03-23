#include<iostream>
#include<queue>
#include<vector>
constexpr int MAX_NUMBER = 100001;

int main() {
	std::priority_queue<int, std::vector<int>, std::greater<>> queue;
	std::vector<int>read_v;
	read_v.reserve(MAX_NUMBER);
	int X;
	std::cin >> X;
	int number;
	for (int i = 0; i < X; ++i) {
		std::cin >> number;
		if (number == 0) {
			if (queue.empty() == false) {
				read_v.emplace_back(queue.top());
				queue.pop();
			}
			else
				read_v.emplace_back(0);
		}
		else {
		queue.emplace(number);
		}
	}
	for (const auto i : read_v)
		std::cout << i << "\n";
}