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

		//������ ����߿��� �湮���� �ʴ� ��带 �ִ´�.
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
	std::cin >> n; //��ǻ���� ����
	std::cin >> m; //��ǻ�� ���� ��

	for (int i = 0; i < m; ++i) {
		int v1, v2;
		std::cin >> v1 >> v2;

		v[v1].emplace_back(v2);
		v[v2].emplace_back(v1);
	}
	BFS(1); //���̷����� 1�� ��ǻ�Ͱ� �ɸ���.
	std::cout << result << "\n";
}
