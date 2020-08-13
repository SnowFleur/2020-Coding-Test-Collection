#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using Element=std::pair<int, bool>;

int ProcessQueue(std::deque<Element>&& printerQueue) {

    int count{};

    while (printerQueue.empty() == false) {
        auto frontValue = printerQueue.front();
        auto maxValue = *std::max_element(printerQueue.begin(), printerQueue.end());

        printerQueue.pop_front();

        //앞에있는게 가장 우선순위가 높다면 
        if (frontValue.first >= maxValue.first) {
            ++count;

            if (frontValue.second == true) {
                return count;
            }
        }
        //우선순위가 더 높은게 queue안에 있다면
        else {
            printerQueue.emplace_back(frontValue);
        }
    }
}


int main() {
    //Test case
    int N{}, queueSize{}, M{};
    std::vector<int> answerVector{};

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::deque<Element> printerQueue;
        std::cin >> queueSize >> M;

        for (int i = 0; i < queueSize; ++i) {
            int value{};
            std::cin >> value;
            if (i == M) {
                printerQueue.emplace_back(Element(std::move(value), true));
            }
            else {
                printerQueue.emplace_back(Element(std::move(value), false));
            }
        }
        answerVector.emplace_back(ProcessQueue(std::move(printerQueue)));
    }
    //Print answer
    for (const auto& answer : answerVector) {
        std::cout << answer << "\n";
    }
}