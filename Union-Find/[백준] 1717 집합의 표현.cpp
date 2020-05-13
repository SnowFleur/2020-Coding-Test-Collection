#include<iostream>
#include<vector>
#include<string>
#include<string_view>
using vector_t = std::vector<int>;

constexpr int MAX_N = 1000001;
constexpr int MAX_M = 100001;
constexpr int COMBINE = 0;
constexpr int CHECK = 1;

void Make_Set(vector_t& nodes, int size) {
	for (int i = 1; i <= size; ++i) {
		nodes[i] = i;
	}
}

int Find(vector_t& nodes, int v) {
	if (nodes[v] == v)
		return v;
	else
		return nodes[v] = Find(nodes, nodes[v]);
}

void Union(vector_t& nodes, int lhs, int rhs) {
	int lhs_parent = Find(nodes, lhs);
	int rhs_parent = Find(nodes, rhs);


	if (lhs_parent < rhs_parent)
		nodes[rhs_parent] = lhs_parent;
	else
		nodes[lhs_parent] = rhs_parent;

}

std::string_view Check_Node(vector_t& nodes, int lhs, int rhs) {
	int lhs_parent = Find(nodes, lhs);
	int rhs_parent = Find(nodes, rhs);

	if (lhs_parent == rhs_parent)
		return "YES";
	else
		return "NO";
}



int main() {
	int N, M;
	vector_t nodes;
	std::vector<std::string> print_v;
	std::cin >> N >> M;

	nodes.assign(N + 1, 0);
	Make_Set(nodes, N);

	for (int i = 0; i < M; ++i) {
		int kind, lhs, rhs;
		std::cin >> kind >> lhs >> rhs;

		if (kind == COMBINE) {
			Union(nodes, lhs, rhs);
		}
		else if (kind == CHECK) {
			print_v.emplace_back(Check_Node(nodes, lhs, rhs));
		}
	}

	for (const auto& i : print_v) {
		std::cout << i << "\n";
	}

}
