#include<queue>
#include<vector>
#include<iostream>

/*
1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
https://www.crocus.co.kr/625
*/

int main() {
    int N{};
    std::cin >> N;
    std::priority_queue<int>maxQueue;
    std::priority_queue<int, std::vector<int>, std::greater<int>>minQueue;

    std::vector<int>printQueue;
    for (int i = 0; i < N; ++i) {
        int answer{};
        std::cin >> answer;

        //사이즈가 0이면 maxQueue에 추가 1번 규칙에 어긋나기 때문
        if (maxQueue.size() == minQueue.size()) {
            maxQueue.push(answer);
        }
        //어긋나지 않으면 min에 추가
        else {
            minQueue.push(answer);
        }
        //
        if (minQueue.empty() == false && maxQueue.empty() == false &&
            maxQueue.top() > minQueue.top()) {
            int maxTop = maxQueue.top();
            int minTop = minQueue.top();
            maxQueue.pop();
            minQueue.pop();
            maxQueue.push(minTop);
            minQueue.push(maxTop);
        }

        printQueue.emplace_back(maxQueue.top());
    }

    for (const auto& value : printQueue) {
        std::cout << value << "\n";
    }
}