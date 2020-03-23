#include<iostream>
#include<vector>
using uint_t = unsigned long long;
void Parametric_Search(uint_t, uint_t);
uint_t maxLen;
uint_t k, n, max = 0;
std::vector<uint_t> lanList;

/*
MAX�� ���� ū ������ ������ �ڸ� �� ��������.

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
		
		//������.
		for (auto i : lanList)
			temp += (i / mid);


		//Left N�� �� ũ�ٸ� �ּ������� �������� �������� �� ���̸� �� ���δ�.
		if (temp < n) {
			max = mid - 1;

		}
		//right �ϴ� �ּ������� ���������� Ȯ��ġ ������ ���������� ����.
		else {
			min = mid + 1;
			maxLen = mid;
		}
		
	}
	
}