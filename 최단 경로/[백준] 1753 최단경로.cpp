#include<iostream>
#include<vector>
#include<queue>
constexpr int MAX_V = 20001;
constexpr int MAX_E = 300001;
constexpr int INF = 2147483647;

class Node {
public:
	int v_;
	int distance_;
	Node() :v_(0), distance_(0) {};
	Node(int v, int distance) :v_(v), distance_(distance) {};

	constexpr bool operator<(const Node& rhs)const {
		return distance_ > rhs.distance_;
	}
};

std::vector<Node>v[MAX_V];
int distance[MAX_V];

void Dijkstra(int started) {
	std::priority_queue<Node> queue; //가장 작은 간선치만 꺼내기 위해 사용
	distance[started] = 0;
	queue.emplace(Node{ started, 0 });
	while (queue.empty() == false) {

		auto top = queue.top();
		queue.pop();

		int n = top.v_; //노드
		int d = top.distance_; //거리

		//최단 거리가 아니라면 넘긴다
		if (d > distance[n])continue;

		//해당 노드와 연결된 노드의 값을 갱신한다.
		for (auto node : v[n]) {

			int aroundNode = node.v_;
			int aroundDistance = node.distance_ + d;

			//현재 노드의 거리값이 더 작다면 갱신한다.
			if (aroundDistance <= distance[aroundNode]) {
				distance[aroundNode] = aroundDistance;
				queue.emplace(Node{ aroundNode, aroundDistance });
			}
		}
	}

}

int main() {
	int V, E, started;
	std::cin >> V >> E;
	std::cin >> started;

	for (int i = 1; i <= V; ++i) {
		distance[i] = INF;
	}

	for (int i = 0; i < E; ++i) {
		int v1, v2, d;
		std::cin >> v1 >> v2 >> d;
		v[v1].emplace_back(Node{ v2, d });
	}
	Dijkstra(started);

	for (int i = 1; i <= V; ++i) {
		if (distance[i] == INF)
			std::cout << "INF\n";
		else
			std::cout << distance[i] << "\n";
	}

}