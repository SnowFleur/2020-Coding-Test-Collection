#include<iostream>
#include<vector>
using uint_t = unsigned long long;
void Parametric_Search(uint_t, uint_t);
uint_t maxLen;
uint_t k, n, max = 0;
std::vector<uint_t> lanList;

/*
MAX를 가장 큰 랜선의 반으로 자른 후 돌려본다.

*/
int main() {
	std::cin >> k >> n;

	for (uint_t i = 0; i < k; ++i) {
		uint_t input;
		std::cin >> input;

		if (max < input)
			max = input;

		lanList.emplace_back(input);
	}

	Parametric_Search(1,0xFFFFFFFFUL);
	std::cout << maxLen;
}

void Parametric_Search(uint_t min, uint_t max) {

	while (min <= max) {

		uint_t mid = (min + max) / 2;
		uint_t temp = 0;
		
		//나눈다.
		for (auto i : lanList)
			temp += (i / mid);


		//Left N이 더 크다면 최소조건을 만족하지 못했으니 더 길이를 더 줄인다.
		if (temp < n) {
			max = mid - 1;

		}
		//right 일단 최소조건을 만족하지만 확실치 않으니 오른쪽으로 간다.
		else {
			min = mid + 1;
			maxLen = mid;
		}
		
	}
	
}