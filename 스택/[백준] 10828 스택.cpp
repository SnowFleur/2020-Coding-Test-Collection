#include<iostream>
#include<vector>
constexpr int NUMBER_OF_OPERATOR     = 10001;
constexpr int NON_DATA               = 0;

std::vector<int> g_read_vector;

struct Node {
public:
	Node():next_(nullptr),value_(NON_DATA) {
	}
	Node* next_;
	int value_;
	Node(int value) :value_(value){
		next_ = nullptr;
	}
};

class Stack {
private:
	size_t size_;
	Node* node_;
public:
	Stack():size_(0) {
		node_ = new Node();
	}
	void push(const int value) {
		Node* nextNode = nullptr;
		nextNode = new Node(value);
		
		nextNode->next_ = node_->next_;
		node_->next_ = nextNode;
		++size_;
	}

	int pop() {
		if (empty())
			return -1;
		
		Node* delete_node = nullptr;
		int return_value{};

		delete_node = node_->next_;
		node_->next_ = node_->next_->next_;
		return_value = delete_node->value_;

		if (delete_node != nullptr)
			delete delete_node;

		--size_;
		return return_value;
	}
	size_t size()const {
		return size_;
	}

	int empty() {
		if (size_ == 0)
			return 1;
		else
			return 0;
	}

	int top() {
		if (empty())
			return -1;
		return node_->next_->value_;
	}
};




int main() {
	int n, value;
	std::cin >> n;
	std::string s;
	Stack stack;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;

		if (s == "push") {
			std::cin >> value;
			stack.push(value);
		}
		else if (s == "pop") {
			g_read_vector.emplace_back(stack.pop());
		}
		else if (s == "size") {
			g_read_vector.emplace_back(stack.size());
		}
		else if (s == "empty") {
			g_read_vector.emplace_back(stack.empty());
		}
		else if (s == "top") {
			g_read_vector.emplace_back(stack.top());
		}
	}

	for (const auto& i : g_read_vector)
		std::cout << i << "\n";

}