#include<iostream>
#include<queue>
#include<utility>
constexpr int MAX_ARRAY_SIZE = 100001;
constexpr int MAX_WEIGHT = 500000;

using pairData = std::pair<int, int>; //index, weight

int g_weight[MAX_ARRAY_SIZE];

void Search(int N, int K) {

    //N과 K가 같은경우
    if (N == K) {
        std::cout << "0\n";
        return;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
        g_weight[i] = MAX_WEIGHT;
    }

    //std::priority_queue<pairData, std::vector<pairData>, std::greater<>>pq;
    std::queue< pairData>pq;

    pq.emplace(pairData{ N,0 });

    while (pq.empty() == false) {
        //auto topValue = pq.top();
        auto topValue = pq.front();

        pq.pop();

        //더하기
        if ((topValue.first + 1 < MAX_ARRAY_SIZE) &&
            (g_weight[topValue.first + 1] > topValue.second + 1)) {
            g_weight[topValue.first + 1] = topValue.second + 1;
            pq.emplace(pairData{ topValue.first + 1,topValue.second + 1 });
        }
        //빼기
        if ((topValue.first - 1 >= 0) && 
            (g_weight[topValue.first - 1] > topValue.second + 1)) {
            g_weight[topValue.first - 1] = topValue.second + 1;
            pq.emplace(pairData{ topValue.first - 1,topValue.second + 1 });
        }
        //곱하기
        if ((topValue.first * 2 < MAX_ARRAY_SIZE) && 
            (g_weight[topValue.first * 2] > topValue.second + 1)) {
            g_weight[topValue.first * 2] = topValue.second + 1;
            pq.emplace(pairData{ topValue.first * 2,topValue.second + 1 });
        }
    }
    std::cout << g_weight[K] << "\n";
}

int main() {
    int N, K; //수빈, 동생
    std::cin >> N >> K;
    Search(N, K);
}