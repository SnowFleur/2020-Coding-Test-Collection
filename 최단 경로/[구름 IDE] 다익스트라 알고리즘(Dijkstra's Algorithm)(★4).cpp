#include<iostream>
#include<queue>
#include<vector>

constexpr int INF = 10000000;

class Node {
private:
public:
	Node(int node, int weight) :node_(node), weight_(weight) {}
	int node_;
	int weight_;
	constexpr bool operator<(const Node& _Right) const {
		return weight_ > _Right.weight_;
	}
};

std::vector <std::vector<Node>> g_nodes;
std::vector<int> g_weight;

void Dijkstra(int started) {
	
	std::priority_queue<Node> queue;
	queue.emplace(Node{started,0});
	g_weight[started] = 0;

	while (queue.empty() == false) {

		Node top_node = queue.top();
		int node = top_node.node_;
		int node_weight = top_node.weight_;
		queue.pop();

		//해당 노드와 연결된 노드들을 본다.
		for (const auto& nodes : g_nodes[node]) {

			int around_node = nodes.node_;
			int around_weight = nodes.weight_;

			int weight = around_weight + node_weight;
			
			if (weight < g_weight[around_node]) {
				g_weight[around_node] = weight;
				queue.emplace(Node{ around_node,weight });
			}
		}
	}

}


int main() {
	int N, E;
	std::cin >> N >> E;

	g_weight.assign(N + 1, INF);
	g_nodes.assign(N + 1, std::vector<Node>(N + 1, Node(0, 0)));

	for (int i = 0; i < E; ++i) {
		int start_node, end_node, weight;
		std::cin >> start_node >> end_node >> weight;
		g_nodes[start_node].emplace_back(Node{ end_node,weight });
		g_nodes[end_node].emplace_back(Node{ start_node,weight });
	}
	int started;
	std::cin >> started;

	Dijkstra(started);

	for(int i=1;i<=N;++i){
		std::cout << i << ": " << g_weight[i] << "\n";
	}
}