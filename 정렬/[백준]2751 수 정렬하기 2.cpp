#include<iostream>
constexpr int  MAX = 1'000'000;
//constexpr int  MAX = 10000;

int tempArray[MAX];

void Merge(int* list, int begin, int mid, int end) {
	int i = begin;
	int j = mid + 1;
	int k = begin;
	for (; k <= end; ++k) {
		if (j > end) tempArray[k] = list[i++];
		else if (i > mid)tempArray[k] = list[j++];
		else if (list[i] < list[j])tempArray[k] = list[i++];
		else tempArray[k] = list[j++];
	}
	for (int t = begin; t <= end; ++t)
		list[t] = tempArray[t];
}

void Split(int* list, int begin, int end) {
	if (begin < end) {
		int middle = (begin + end) / 2;
		Split(list, begin, middle); //拌加 唱传促.
		Split(list, middle + 1, end);// 拌加 唱传促.
		Merge(list, begin, middle, end);
	}
	else return;
}


int list[MAX];
int main() {
	int max;
	std::cin >> max;
	for (int i = 0; i < max; ++i) {
		std::cin >> list[i];
	}
	Split(list, 0, max - 1);

	for (int i = 0; i < max; ++i)
		std::cout << list[i] << "\n";
}