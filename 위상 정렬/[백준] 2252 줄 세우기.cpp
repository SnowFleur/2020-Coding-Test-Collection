#include<iostream>
#include<vector>
#include<queue>
constexpr int MAX_N = 32001;

std::vector<int> g_nodes[MAX_N];
std::vector<int> g_result;
int g_weight[MAX_N];

void TopologySort(int N) {
    std::queue<int> q;

    //가중치가 0인 노드를 찾아서 queue에 넣는다.
    for (int i = 1; i <= N; ++i) {
        if (g_weight[i] == 0) {
            q.emplace(i);
        }
    }
    //N개의 노드를 방문
    for (int i = 1; i <= N; ++i) {

        auto front_value = q.front();
        q.pop();
        g_result.emplace_back(front_value);
        //해당 노드와 연결된 노드의 가중치를 제거한다.
        for (const auto& i : g_nodes[front_value]) {
            g_weight[i]--;
            if (g_weight[i] == 0) {
                q.emplace(i);
            }
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    

    for (int i = 0; i < M; ++i) {
        int lhs, rhs;
        std::cin >> lhs >> rhs;
        // lhs<---rhs
        g_nodes[lhs].emplace_back(rhs);
        g_weight[rhs]++;
    }
    TopologySort(N);
    for (const auto& i : g_result) {
        std::cout << i << " ";
    }
}