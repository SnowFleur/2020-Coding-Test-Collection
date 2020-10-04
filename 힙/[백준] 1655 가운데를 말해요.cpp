#include<queue>
#include<vector>
#include<iostream>

/*
1. �ִ� ���� ũ��� �ּ� ���� ũ��� ���ų�, �ϳ� �� ũ��.
2. �ִ� ���� �ִ� ���Ҵ� �ּ� ���� �ּ� ���Һ��� �۰ų� ����.
�̶� �˰��� ���� �ʴٸ� �ִ� ��, �ּ� ���� ���� ���� ���� swap���ش�.
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

        //����� 0�̸� maxQueue�� �߰� 1�� ��Ģ�� ��߳��� ����
        if (maxQueue.size() == minQueue.size()) {
            maxQueue.push(answer);
        }
        //��߳��� ������ min�� �߰�
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