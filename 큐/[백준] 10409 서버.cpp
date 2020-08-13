#include<iostream>
#include<queue>

int main() {
    int N{}, T{};
    std::queue<int>queue;
    std::cin >> N >> T;

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        queue.emplace(value);
    }

    int sumCount{ 0 };
    int index{ 0 };
    while (queue.empty() == false) {
        int frontValue = queue.front();
        queue.pop();

        sumCount += frontValue;
        if (sumCount > T) {
            break;
        }
        ++index;
    }
    std::cout << index << "\n";
}


