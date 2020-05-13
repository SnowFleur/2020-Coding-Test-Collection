#include<iostream>
#include<vector>
#include<queue>
constexpr int MAX_N = 32001;

std::vector<int> g_nodes[MAX_N];
std::vector<int> g_result;
int g_weight[MAX_N];

void TopologySort(int N) {
    std::queue<int> q;

    //����ġ�� 0�� ��带 ã�Ƽ� queue�� �ִ´�.
    for (int i = 1; i <= N; ++i) {
        if (g_weight[i] == 0) {
            q.emplace(i);
        }
    }
    //N���� ��带 �湮
    for (int i = 1; i <= N; ++i) {

        auto front_value = q.front();
        q.pop();
        g_result.emplace_back(front_value);
        //�ش� ���� ����� ����� ����ġ�� �����Ѵ�.
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