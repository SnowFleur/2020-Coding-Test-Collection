#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;
using my_queue = priority_queue<int, vector<int>, greater<int>>;

bool CheckScoville(my_queue queue, int K);
int solution(vector<int> scoville, int K) {
	int index{ 1 };
	int low_food{ 0 }, low_food2{ 0 };
	my_queue queue;

	for (auto i : scoville)
		queue.emplace(i);

	while (!queue.empty()) {
		low_food = queue.top();
		queue.pop();
		
		if (!queue.empty()) {
			low_food2 = queue.top();
			queue.pop();
		}
		else
			return -1;

		queue.emplace(low_food + low_food2 * 2);

		if (K <= low_food + low_food2 * 2) {
			if (CheckScoville(queue, K) == true) {
				return index;
			}
		}
		++index;
	}
	return -1;
}

bool CheckScoville(my_queue queue, int K) {
	while (!queue.empty()) {
		auto value = queue.top();
		queue.pop();
		if (value < K) {
			return false;
		}
	}
	return true;
}


