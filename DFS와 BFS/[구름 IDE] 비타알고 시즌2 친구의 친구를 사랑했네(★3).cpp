#include<iostream>
#include<vector>
#include<algorithm>
using graph_t = std::vector<std::vector<int>>;
using visited_t = std::vector<bool>;
using count_t = std::vector<size_t>;
/*
N: 사람의 수
E:  관계의 수
*/
int g_index;
count_t g_count;
void DFS(int started, graph_t& v, visited_t& visited) {

	visited[started] = true;
	g_count[g_index]++;
	for (const auto& values : v[started]) {

		//아직 방문하지 않은 노드라면
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

	//방향 그래프
	int v1, v2;
	for (int i = 0; i < E; ++i) {
		std::cin >> v1 >> v2;
		v[v1].emplace_back(v2);
	}

	//어느 노드가 가장 많은 개수를 가졌는지 알아야 하기 때문에
	//모든 정점을 시작점으로 한다.
	for (int i = 1; i <= N; ++i) {
		g_index = i;
		visited.assign(N + 1, false);
		DFS(i, v, visited);
	}
	//가장 큰 값을 가진 반복자 리턴
	auto iter=std::max_element(g_count.begin(), g_count.end());
	//인덱스 출력
	std::cout << iter-g_count.begin();


}


#include<iostream>
int main() {
	std::cout << "Hello World \n";
}
