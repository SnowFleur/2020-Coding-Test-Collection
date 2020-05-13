#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
constexpr int MAX_N = 26;


using Point = std::pair<int, int>;

struct Node {
    int value_;
    bool visited_;
};


void BFS(std::vector <std::vector<Node>>& graph, int N) {
    std::queue<Point> queue;
    std::vector<int> result;
    int count{};
    int total{};

    for (int xpos = 0; xpos < N; ++xpos) {
        for (int ypos = 0; ypos < N; ++ypos) {
            if (graph[xpos][ypos].visited_ == true)continue;

            queue.emplace(Point{ xpos,ypos });
            count = 0;
            while (queue.empty() == false) {
                auto frontValue = queue.front();

                queue.pop();
                int x = frontValue.first;
                int y = frontValue.second;
                graph[x][y].visited_ = true;

                if (graph[x][y].value_ == 0)
                    break;

                //╩С
                if (y >= 1) {
                    if (graph[x][y - 1].value_ == 1 && graph[x][y - 1].visited_ == false) {
                        graph[x][y - 1].visited_ = true;
                        queue.emplace(Point{ x, y - 1 });
                    }
                }
                //го
                if (y <= N) {
                    if (graph[x][y + 1].value_ == 1 && graph[x][y + 1].visited_ == false) {
                        graph[x][y + 1].visited_ = true;
                        queue.emplace(Point{ x, y + 1 });
                    }
                }
                //аб
                if (x >= 1) {
                    if (graph[x - 1][y].value_ == 1 && graph[x - 1][y].visited_ == false) {
                        graph[x - 1][y].visited_ = true;
                        queue.emplace(Point{ x - 1, y });
                    }
                }
                //©Л
                if (x <= N) {
                    if (graph[x + 1][y].value_ == 1 && graph[x + 1][y].visited_ == false) {
                        graph[x + 1][y].visited_ = true;
                        queue.emplace(Point{ x + 1, y });
                    }
                }
                ++count;
            }
            if (count != 0) {
                result.emplace_back(count);
                ++total;
            }
        }
    }

    std::cout << total << "\n";
    std::sort(result.begin(), result.end(), std::less<int>());

    for (const auto& i : result)
        std::cout << i << "\n";

}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<Node>>v(N+1,std::vector<Node>(N+1));

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            int value;
            scanf("%1d", &value);
            v[x][y] = Node{ value,false };
        }
    }
    BFS(v,N);
}