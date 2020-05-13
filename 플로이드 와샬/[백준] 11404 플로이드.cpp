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
	// k: �߰� ���� ����
	// i: ���� ����
	// j: ������ ����
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
	//��� ��θ� INF�� ����
	MakeSet(N);

	//���� �Է�
	for (int i = 0; i < M; ++i) {
		std::cin >> from_v >> to_v >> weight;
		//�� ���� ���� ������ �ٲ۴�.
		if (g_graph[from_v][to_v] > weight) {
			g_graph[from_v][to_v] = weight;
		}

	}
	//�÷��̵�-�ͼ� �˰��� ����
	FloyedWarshall(N);

	//���
	DisplayAll(N);
}

