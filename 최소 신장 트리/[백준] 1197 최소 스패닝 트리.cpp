#include<iostream>
#include<algorithm>
#include<vector>
constexpr int MAX_V = 10001;
constexpr int MAX_E = 100001;
using namespace std;
using llong_t = long long;
int GetParent(int);
void Unione(int,int);
bool Find(int,int);

struct Edge {
public:
	int v1 = 0;
	int v2 = 0;
	int weight = 0;
	Edge(int vertex, int vertex2, int edgeWeight) :v1(vertex), v2(vertex2), weight(edgeWeight) {}
	constexpr bool operator<(const Edge& lhs)const {
		return weight < lhs.weight;
	}
};

std::vector<Edge> nodeList;
int nodeParentInfo_[MAX_V];

int main() {
	int A, B, C;
	int numV, numE;
	std::cin >> numV >> numE;

	for (int i = 0; i < numE; ++i) {
		std::cin >> A >> B >> C;
		nodeList.emplace_back(Edge{ A,B,C });
	}

	//오름차순 정렬
	std::sort(nodeList.begin(), nodeList.end());

	//부몬 노드 정보 초기화
	for (int i = 0; i < MAX_V; ++i)
		nodeParentInfo_[i] = i;


	llong_t result = 0;
	for (int i = 0; i < nodeList.size(); ++i) {
		if (Find(nodeList[i].v1, nodeList[i].v2) == false) {
			result += nodeList[i].weight;
			Unione(nodeList[i].v1, nodeList[i].v2);
		}
	}

	std::cout << result << "\n";
}

int GetParent(int v) {
	if (nodeParentInfo_[v] == v)
		return v;
	else
		return nodeParentInfo_[v] = GetParent(nodeParentInfo_[v]);
}

void Unione(int lhs, int rhs) {
	int v1 = GetParent(lhs);
	int v2 = GetParent(rhs);

	//더 작은 노드가 부모
	if (v1 < v2)
		nodeParentInfo_[v2] = v1;
	else
		nodeParentInfo_[v1] = v2;
}

bool Find(int lhs, int rhs) {
	int v1 = GetParent(lhs);
	int v2 = GetParent(rhs);

	if (v1 == v2)
		return true;
	else
		return false;
}
