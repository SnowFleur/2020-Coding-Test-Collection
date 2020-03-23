#include<iostream>
#include<string_view>

using string_view = std::string_view;

class Node {
private:
public:
	Node() = default;
	Node(const string_view s) :left_(nullptr), right_(nullptr), name_{s.data()}{}
	std::string name_;
	Node* left_;
	Node* right_;
};

class Tree {
private:
	Node* node_;
public:
	Tree()= default;
	Tree(const std::string& s)  {
		node_ = new Node(s);
	}
	
	void SearchRoot(const std::string& root_name,Node* root,Node** result_node) {
		
		if (root == nullptr)
			return;
		
		if (root->name_ == root_name)
			*result_node = root;

		SearchRoot(root_name, root->left_, result_node);
		SearchRoot(root_name, root->right_, result_node);
	}

	void Insert(const string_view root_name, const string_view left_name, const string_view right_name) {

		Node* result_node = nullptr;
		SearchRoot(root_name.data(), node_, &result_node);

		if (result_node != nullptr) {
			Node* newNode = nullptr;
			if (left_name != ".") {
				newNode = new Node(left_name.data());
				result_node->left_ = newNode;
			}
			if (right_name != ".") {
				newNode = new Node(right_name.data());
				result_node->right_ = newNode;
			}
		}
		
	}
	void DisplayAll()const {
		PreOrder(node_);
		std::cout << "\n";
		InOrder(node_);
		std::cout << "\n";
		PostOrder(node_);
		std::cout << "\n";
	}

	//ÀüÀ§ Å½»ö
	void PreOrder(const Node* node)const {
		if (node == nullptr)
			return;
		
		std::cout << node->name_;
		PreOrder(node->left_);
		PreOrder(node->right_);
	}

	//ÁßÀ§ Å½»ö
	void InOrder(const Node* node)const {
		if (node == nullptr)
			return;
		
		InOrder(node->left_);
		std::cout << node->name_;
		InOrder(node->right_);
	}
	//ÈÄÀ§ Å½»ö
	void PostOrder(const Node* node)const {
		if (node == nullptr)
			return;

		PostOrder(node->left_);
		PostOrder(node->right_);
		std::cout << node->name_;
	}

};


int main() {
	Tree tree("A");
	int N;
	std::cin >> N;
	std::string root,left,right;

	for (int i = 0; i < N; ++i) {
		std::cin >> root >> left >> right;
		tree.Insert(root, left, right);
	}
	tree.DisplayAll();
}