#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
constexpr int MAX_WEIGHT = 5000000;
std::vector<std::vector<int>> g_nodes;
std::vector<std::vector<int>> g_weight;
int N, M;

class Node {
public:
    int y_;
    int x_;
    int weight_;
    Node() = default;
    Node(int y, int x, int weight) :y_(y), x_(x), weight_(weight) {};
};

void BFS() {
    std::queue<Node> queue;
    queue.emplace(Node{ 0,0,1 });
    //���������� Ž������
    //���� �ٲ��� �������� y,x ������ ����
    while (queue.empty() == false) {
        int y = queue.front().y_;
        int x = queue.front().x_;
        int weight = queue.front().weight_;
        queue.pop();

        //Ž���� ��������ϸ鼭 �� ���� ����ġ�� �ִٸ� �ٲ۴�.
        if (g_weight[y][x] > weight) {
            g_weight[y][x] = weight;
        }
        //����ġ�� �� ũ�ٸ� �� ��� ���ʿ䰡 �ֳ�?
        else {
            continue;
        }

        //����
        if (x - 1 >= 0 && g_nodes[y][x - 1] == 1 ) {
            queue.emplace(Node{ y,x - 1,weight + 1 });
        }
        //������
        if (x + 1 < M && g_nodes[y][x + 1] == 1 ) {
            queue.emplace(Node{ y,x + 1,weight + 1 });
        }
        //��
        if (y - 1 >= 0 && g_nodes[y - 1][x] == 1 ) {
            queue.emplace(Node{ y - 1,x,weight + 1 });
        }
        //�Ʒ�
        if (y + 1 < N && g_nodes[y + 1][x] == 1 ) {
            queue.emplace(Node{ y + 1,x,weight + 1 });
        }

    }
}


int main() {
    std::cin >> N >> M;
    
    g_nodes.assign(N,std::vector<int>(M,0));
    g_weight.assign(N, std::vector<int>(M, MAX_WEIGHT));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int value;
            scanf("%1d", &value);
            g_nodes[i][j] = value;
        }
    }

    BFS();

    std::cout << g_weight[N-1][M-1] << "\n";
}