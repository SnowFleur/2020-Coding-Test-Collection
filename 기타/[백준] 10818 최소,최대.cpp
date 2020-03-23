#include<iostream>
#include<algorithm>
#include<array>
constexpr int ARRAY_MAX = 1000001;

std::array<int, ARRAY_MAX>arr;
int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int number;
		std::cin >> number;
		arr[i] = number;
	}
	auto min_ele=std::min_element(arr.begin(), arr.begin()+N);
	auto max_ele = std::max_element(arr.begin(), arr.begin() + N);

	std::cout << *min_ele << " " << *max_ele << "\n";

}