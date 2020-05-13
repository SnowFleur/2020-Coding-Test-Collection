#include<iostream>
#include<vector>
#include<algorithm>
constexpr int MAX_N = 200001;
using graph_t = std::vector<int>;
using node_count_t = std::vector<size_t>;

int Find(int value, graph_t& g) {

	if (g[value] == value)
		return value;
	else
		return g[value] = Find(g[value], g);

}

void Union(int lhs, int rhs, graph_t& g) {

	int lhs_parents = Find(lhs, g);
	int rhs_parents = Find(rhs, g);

	if (lhs_parents < rhs_parents) {
		g[rhs_parents] = lhs_parents;
	}
	else {
		g[lhs_parents] = rhs_parents;
	
	}
}
void CheckMaxNode(node_count_t& count_array, graph_t& g) {

	//����� ���տ��� �θ� ������ ã�´�.
	for (const auto& i : g) {
		int parents = Find(i, g);
		//�ش� �θ����� index���� ������Ų��.
		count_array[parents]++;
	}
	//���� ū ���� ���� �ݺ��ڸ� ã�´�.
	auto iter = std::max_element(count_array.begin(), count_array.end());
	int index = iter - count_array.begin();
	std::cout << index << " " << *iter<<"\n";
}


void MakeSet(graph_t& g, int N) {
	//Initlization
	for (int i = 1; i <= N; ++i)
		g[i] = i;
}

int main() {
	int N{}, M{}, from_v{}, to_v{};
	std::cin >> N >> M;

	graph_t g(N + 1);
	node_count_t count_array(N + 1, 0);
	MakeSet(g, N);

	for (int i = 0; i < M; ++i) {
		std::cin >> from_v >> to_v;
		Union(from_v, to_v, g);
	}
	CheckMaxNode(count_array,g);

}