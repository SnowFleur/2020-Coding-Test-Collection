#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using NODE = std::vector<std::vector<int>>;
std::vector<bool>   g_visited;

void DFS(NODE& n,int S) {
    int weight=1;
    std::stack<int> s;
    s.emplace(S);

    while (s.empty() == false) {
        auto topVaule = s.top();
        s.pop();
        g_visited[topVaule] = true;

        for (const auto& node : n[topVaule]) {
            if (g_visited[node] == false) {
                ++weight;
                s.emplace(node);
            }
        }
    }
    std::cout << weight << "\n";
}

int main() {
    //N 과목의 수, M 관계의 수 , 졸업하기 위해 들어야하는 과목 C
    int N, M, C;
    std::cin >> N >> M;
    NODE n(N + 1);
    g_visited.assign(N + 1, false);

    int s{}, e{};
    for (int i = 0; i < M; ++i) {
        // s start, e end
        std::cin >> s >> e;
        //Reverse
        n[e].emplace_back(s);
    }
    std::cin >> C;
    DFS(n, C);
}