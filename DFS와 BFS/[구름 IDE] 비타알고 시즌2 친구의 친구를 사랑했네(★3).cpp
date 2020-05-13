#include<iostream>
#include<vector>
#include<algorithm>
using graph_t = std::vector<std::vector<int>>;
using visited_t = std::vector<bool>;
using count_t = std::vector<size_t>;
/*
N: ����� ��
E:  ������ ��
*/
int g_index;
count_t g_count;
void DFS(int started, graph_t& v, visited_t& visited) {

	visited[started] = true;
	g_count[g_index]++;
	for (const auto& values : v[started]) {

		//���� �湮���� ���� �����
		if (visited[values] == false) {
			 DFS(values, v, visited);
		}
	}
}



int main() {
	int N, E;
	std::cin >> N >> E;

	graph_t v(N + 1);
	visited_t visited(N + 1, false);
	g_count.assign(N + 1, 0);

	//���� �׷���
	int v1, v2;
	for (int i = 0; i < E; ++i) {
		std::cin >> v1 >> v2;
		v[v1].emplace_back(v2);
	}

	//��� ��尡 ���� ���� ������ �������� �˾ƾ� �ϱ� ������
	//��� ������ ���������� �Ѵ�.
	for (int i = 1; i <= N; ++i) {
		g_index = i;
		visited.assign(N + 1, false);
		DFS(i, v, visited);
	}
	//���� ū ���� ���� �ݺ��� ����
	auto iter=std::max_element(g_count.begin(), g_count.end());
	//�ε��� ���
	std::cout << iter-g_count.begin();


}


#include<iostream>
int main() {
	std::cout << "Hello World \n";
}
