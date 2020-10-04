#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

constexpr int MAX_COMPUTERS = 201;

bool g_visited[MAX_COMPUTERS];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    std::vector<int>network(n+1, 0);

    for (int i = 0; i < n; ++i) {

        std::queue<int>queue;
        queue.emplace(i);

        while (queue.empty() == false) {

            auto frontNode = queue.front();
            queue.pop();

            for (int j = 0; j < computers[frontNode].size(); ++j) {

                if (computers[frontNode][j] == 1 && g_visited[j] == false) {
                    g_visited[j] = true;
                    queue.emplace(j);
                    network[i]++;
                }
            }
        }
    }

    answer=std::count_if(network.begin(), network.end(), [](auto& value) {
        return value > 0;
    });

    return answer;
}

#include<iostream>
int main() {

    int n = 3;
    vector<vector<int>> computers{ {1,1,0},{1,1,0},{0,0,1} };


   /* int n = 3;
    vector<vector<int>> computers{ {1,1,0},{1,1,1},{0,1,1} };*/


    std::cout << solution(n, computers) << "\n";
}