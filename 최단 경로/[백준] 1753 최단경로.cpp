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
	std::priority_queue<Node> queue; //���� ���� ����ġ�� ������ ���� ���
	distance[started] = 0;
	queue.emplace(Node{ started, 0 });
	while (queue.empty() == false) {

		auto top = queue.top();
		queue.pop();

		int n = top.v_; //���
		int d = top.distance_; //�Ÿ�

		//�ִ� �Ÿ��� �ƴ϶�� �ѱ��
		if (d > distance[n])continue;

		//�ش� ���� ����� ����� ���� �����Ѵ�.
		for (auto node : v[n]) {

			int aroundNode = node.v_;
			int aroundDistance = node.distance_ + d;

			//���� ����� �Ÿ����� �� �۴ٸ� �����Ѵ�.
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