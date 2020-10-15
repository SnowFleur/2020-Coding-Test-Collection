#include<iostream>
#include<vector>
#include<queue>
#include<utility>

bool visited[501];

using Data = std::pair<int, int>; //Node, Depth

void BFS(std::vector<std::vector<int>>& list) {

    /*
    1������ ���̸� 2���� ����ϸ� ģ���� ģ�������� ���� �� ������
    */

    std::queue<Data> queue;
    int count{};
    //����� �й��� 1���̱� ������ 1�� �ְ� ����
    queue.emplace(1,0);
    visited[1] = true;

    while (queue.empty() == false) {
        auto frontValue = queue.front();
        queue.pop();

        for (auto& v : list[frontValue.first]) {
            //�湮���� ���� ����� �ְ� Ž��
            if (visited[v] == false) {
                visited[v] = true;
                queue.emplace(Data{ v,frontValue.second + 1 });

                if (frontValue.second < 2) {
                    ++count;
                }
            }
        }
    }
    std::cout << count << "\n";
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>>list(n + 1);

    for (int i = 0; i < m; ++i) {
        int me, other;
        std::cin >> me >> other;
        list[me].emplace_back(other);
        list[other].emplace_back(me);
    }
    BFS(list);
}