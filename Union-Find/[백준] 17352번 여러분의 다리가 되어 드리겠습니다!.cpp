#include<iostream>
#include<vector>

int Find(const int i, std::vector<int>& g) {
    if (g[i] == i)
        return i;
    else
        return g[i] = Find(g[i], g);
}

void Union(const int lhs, const int rhs, std::vector<int>& g, std::vector<int>& r) {
    int lhs_parent = Find(lhs, g);
    int rhs_parent = Find(rhs, g);

    //같은 집합이면 stop
    if (lhs_parent == rhs_parent)return;

    //랭크가 더 높은걸 작은쪽으로 합친다.
    if (r[lhs_parent] > r[rhs_parent]) {
        g[rhs_parent] = lhs_parent;
    }
    else {
        g[lhs_parent] = rhs_parent;
        if (r[lhs_parent] == r[rhs_parent]) {
            r[lhs_parent]++;
        }
    }
}

bool SearchSameParent(const int lhs, const int rhs, std::vector<int>& g) {
    int lhs_parent = Find(lhs, g);
    int rhs_parent = Find(rhs, g);

    if (lhs_parent == rhs_parent)return true;

    return false;
}

int main() {

    //C++ 입출력 속도
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n{};
    std::cin >> n;
    std::vector<int> g(n + 1, 0);
    std::vector<int> r(n + 1, 0);

    //make graph
    for (int i = 1; i <= n; ++i)
        g[i] = i;

    //N-2개 까지 받는다.
    for (int i = 1; i <= n - 2; ++i) {
        int lhs, rhs;
        std::cin >> lhs >> rhs;
        Union(lhs, rhs, g, r);
    }

    for (int i = 1; i <= n - 1; ++i) {
        if (SearchSameParent(i, i + 1, g) == false) {
            std::cout << i << " " << i + 1 << "\n";
            break;
        }
    }
}