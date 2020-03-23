#include<iostream>
#include<queue>                  
const int MAX_VERTEX = 1001;
const int MAX_EDGE = 10001;
class cmp;
std::priority_queue<int, std::vector<int>, cmp>* bfs_q;
std::priority_queue<int, std::vector<int>, cmp>* dfs_q;

bool bfs_visited[MAX_VERTEX];
bool dfs_visited[MAX_VERTEX];


class cmp {
public:
	bool operator()(int lhs, int rhs) {
		return lhs > rhs;
	}
};

//using recursive call
void DFS(int started) {

	auto iter = dfs_q[started];
	if (dfs_visited[started] == false) {
		dfs_visited[started] = true;
		std::cout << started << " ";
	}

	while (!iter.empty()) {
		int i = iter.top();
		iter.pop();
		if (dfs_visited[i] == false) {
			DFS(i);
		}
	}
	return;
}

//using Queue
void BFS(int started) {
	std::queue<int> q;
	q.push(started);
	bfs_visited[started] = true;
	std::cout << started << " ";
	while (!q.empty()) {
		auto iter = bfs_q[q.front()];
		q.pop();

		while (!iter.empty()) {
			int i = iter.top();
			iter.pop();
			if (bfs_visited[i] == false) {
				bfs_visited[i] = true;
				q.push(i);
				std::cout << i << " ";
			}
		}

	}
}

int main() {

	int vertex = 0;
	int edge = 0;
	int started = 0;
	std::cin >> vertex >> edge >> started;

	bfs_q = new std::priority_queue<int, std::vector<int>, cmp>[vertex + 1];
	dfs_q = new std::priority_queue<int, std::vector<int>, cmp>[vertex + 1];

	for (int i = 0; i < MAX_VERTEX; ++i) {
		bfs_visited[i] = false;
		dfs_visited[i] = false;
	}

	for (int i = 0; i < edge; ++i) {
		int from_v, to_v;
		std::cin >> from_v >> to_v;

		bfs_q[from_v].push(std::move(to_v));
		dfs_q[from_v].push(std::move(to_v));

		bfs_q[to_v].push(std::move(from_v));
		dfs_q[to_v].push(std::move(from_v));
	}
	DFS(started);
	std::cout << "\n";
	BFS(started);

}