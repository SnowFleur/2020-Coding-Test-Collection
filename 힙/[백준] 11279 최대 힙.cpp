#include<iostream>
#include<vector>
constexpr int MAX_INDEX = 1000002;
std::vector<int> read_v;

class Heap {
private:
	int value_[MAX_INDEX];
	int size_;
	void Swap(int& lhs, int& rhs) {
		int temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
public:
	Heap() :size_(0) {
		for (int i = 0; i < MAX_INDEX; ++i) {
			value_[i] = -1;
		};
	}
	int GetNode(int curr) {
		int left = curr * 2;
		int right = curr * 2 + 1;

		// 자식이 없다.
		if (left > size_) {
			return 0;
		}
		//왼쪽 자식만 있다.
		else if (left == size_) {
			return left;
		}

		//자식이 둘다 있다.
		else {
			if (value_[left] > value_[right])
				return left;
			else
				return right;
		}
	}

	void Pop() {
			if (size_ == 0) {
				read_v.emplace_back(0);
			}
			else {
				int	highValue = value_[1];
				int index = size_;
				int curr = 1;
				value_[1] = value_[index];

				//위에서 아래로 
				while (int node = GetNode(curr)) {
					//자식 노드가 더 크다면 바꾼다.
					if (value_[node] > value_[curr]) {
						Swap(value_[node], value_[curr]);
						curr = node;
					}
					else
						break;
				}
				--size_;
				read_v.emplace_back(highValue);
			}
	}

	//처음에 값을 넣을 때 맨 마지막에 넣는다.
	void Push(int value) {
		//값을 제거하고 출력한다.
		if (value == 0) {
			Pop();
		}
		else {
			int index = size_ + 1;
			value_[index] = value;
			int parent = index / 2;
			
			//아래에서 위로 이동
			while (index!=1) {
				if (value_[index] > value_[parent]) {
					Swap(value_[index], value_[parent]);
					index = parent;
					parent = index / 2;
				}
				else
					break;
			}
			++size_;
		}
	}
};

/*
1. 입력된 N까지 값을 넣는다.

2. 0을 입력하면 배열에서 가장 큰값을 출력하고 그 값을 배열에서 제거하는 경우이다.

3. 출력은 마지막에 진행되기 때문에 출력 전용 컨테이너를 만든다.
*/


Heap list{};
int main() {
	int n, x;
	std::cin >> n;
	read_v.reserve(MAX_INDEX);
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		list.Push(x);
	}
	for (auto& i : read_v)
		std::cout << i << "\n";

}