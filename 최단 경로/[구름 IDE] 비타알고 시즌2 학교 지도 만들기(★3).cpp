#include<iostream>
#include<queue>

constexpr int MAX_V = 20001;
constexpr int MAX_E = 100001;
constexpr int INF = INT32_MAX;

using namespace std;

struct Node {
	int		node;
	int		weight;
public:
	Node() = default;
	Node(int n,int w):node(n),weight(w) {}
	bool operator<(const Node& rhs)const {
		return weight > rhs.weight;
	}

};


void Dijkstra(int started,std::vector<vector<Node>>& vs, vector<int>& ws) {
	priority_queue<Node> queue;
	ws[started] = 0;
	queue.emplace(Node{ started,0 });

	while (queue.empty() == false) {
		
		int n = queue.top().node;
		int w = queue.top().weight;
		queue.pop();

		for (const auto& i : vs[n]) {
			int around_n = i.node;
			int around_w = i.weight+w;
			if (ws[around_n] > around_w) {
				ws[around_n] = around_w;
				queue.emplace(Node{ around_n,around_w });
			}
		}
	}
}

int main() {
	int V, E;
	int u, v, w;
	int x;
	std::cin >> V >> E;

	vector<vector<Node>>	nodes(V + 1);
	vector<int>				weight(V + 1, INF);

	for (int i = 0; i < E; ++i) {
		std::cin >> u >> v >> w;
		nodes[u].emplace_back(Node{ v,w });
		nodes[v].emplace_back(Node{ u,w });

	}
	std::cin >> x;
	Dijkstra(x, nodes, weight);

	for (int i = 1; i <= V; ++i) {
		if (weight[i] == INF)
			std::cout << -1 << "\n";
		else
			std::cout << weight[i] << "\n";

	}
}
