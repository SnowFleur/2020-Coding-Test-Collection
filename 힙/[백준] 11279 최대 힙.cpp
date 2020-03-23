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

		// �ڽ��� ����.
		if (left > size_) {
			return 0;
		}
		//���� �ڽĸ� �ִ�.
		else if (left == size_) {
			return left;
		}

		//�ڽ��� �Ѵ� �ִ�.
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

				//������ �Ʒ��� 
				while (int node = GetNode(curr)) {
					//�ڽ� ��尡 �� ũ�ٸ� �ٲ۴�.
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

	//ó���� ���� ���� �� �� �������� �ִ´�.
	void Push(int value) {
		//���� �����ϰ� ����Ѵ�.
		if (value == 0) {
			Pop();
		}
		else {
			int index = size_ + 1;
			value_[index] = value;
			int parent = index / 2;
			
			//�Ʒ����� ���� �̵�
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
1. �Էµ� N���� ���� �ִ´�.

2. 0�� �Է��ϸ� �迭���� ���� ū���� ����ϰ� �� ���� �迭���� �����ϴ� ����̴�.

3. ����� �������� ����Ǳ� ������ ��� ���� �����̳ʸ� �����.
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