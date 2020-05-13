#include<iostream>

constexpr int MAX_N = 101;
constexpr int MAX_M = 10000001;


int g_graph[MAX_N][MAX_N];

void DisplayAll(int node_count) {
	for (int i = 1; i <= node_count; ++i) {
		for (int j = 1; j <= node_count; ++j) {
			if (g_graph[i][j] == MAX_M) {
				std::cout << "0 ";
			}
			else
				std::cout << g_graph[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void MakeSet(int node_count) {
	for (int i = 1; i <= node_count; ++i) {
		for (int j = 1; j <= node_count; ++j) {
			if (i != j)
				g_graph[i][j] = MAX_M;
		}
	}
}

void FloyedWarshall(int node_count) {
	// k: 중간 정점 집합
	// i: 시작 정점
	// j: 마지막 정점
	//  MIN( [i][j],[i][k]+[k][j] )
	for (int k = 1; k <= node_count; ++k) {
		for (int i = 1; i <= node_count; ++i) {
			for (int j = 1; j <= node_count; ++j) {
				if (g_graph[i][j] > g_graph[i][k] + g_graph[k][j]) {
					g_graph[i][j] = g_graph[i][k] + g_graph[k][j];
				}
			}
		}
	}
}

int main() {
	int N, M;
	int from_v, to_v, weight;

	std::cin >> N >> M;
	//모든 경로를 INF로 설정
	MakeSet(N);

	//정보 입력
	for (int i = 0; i < M; ++i) {
		std::cin >> from_v >> to_v >> weight;
		//더 작은 간선 정보로 바꾼다.
		if (g_graph[from_v][to_v] > weight) {
			g_graph[from_v][to_v] = weight;
		}

	}
	//플로이드-와샬 알고리즘 실행
	FloyedWarshall(N);

	//출력
	DisplayAll(N);
}

