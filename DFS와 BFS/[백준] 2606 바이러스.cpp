#include<iostream>
#include<vector>
#include<queue>
constexpr int MAX_COMPUTER = 101;
bool visited[MAX_COMPUTER];
std::vector<int> v[MAX_COMPUTER];
int result;

void BFS(int started) {
	std::queue<int> q;

	q.emplace(started);
	visited[started] = true;

	while (q.empty() == false) {
		
		int node = q.front();
		q.pop();

		//인접한 노드중에서 방문하지 않는 노드를 넣는다.
		for (auto i : v[node]) {
			if (visited[i] == false) {
				++result;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	int n, m;
	std::cin >> n; //컴퓨터의 개수
	std::cin >> m; //컴퓨터 쌍의 수

	for (int i = 0; i < m; ++i) {
		int v1, v2;
		std::cin >> v1 >> v2;

		v[v1].emplace_back(v2);
		v[v2].emplace_back(v1);
	}
	BFS(1); //바이러스는 1번 컴퓨터가 걸린다.
	std::cout << result << "\n";
}
