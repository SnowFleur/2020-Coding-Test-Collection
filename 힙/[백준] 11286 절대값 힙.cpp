#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<math.h>

constexpr int POP = 0;
using priority_queue = std::priority_queue<int, std::vector<int>, std::greater<int>>;
using MinusCounter = std::pair<int, int>;

// Zero number is pop 
// other numbers is push

int main() {
    priority_queue heap;
    std::vector<int> printVector;
    std::map<int,int> map;
    int total{};

    std::cin >> total;
    for (int i = 0; i < total; ++i) {
        int value{};
        std::cin >> value;

        if (value == POP) {
            // if Queue is Empty print Zero
            if (heap.empty() == true) {
                printVector.emplace_back(0);
            }
            else {
                auto TopVaule = heap.top();
                auto iter = map.find(TopVaule);

                if (iter != map.end() && iter->second > 0) {
                    iter->second--;
                    TopVaule *= -1;
                }

                printVector.emplace_back(TopVaule);
                heap.pop();
            }

        }
        else {
            //0보다 작다면 map에 값을 저장하자
            if (value < 0) {
                auto iter = map.find(abs(value));
                //찾아보고 있다면 증가
                if (iter != map.end()) {
                    iter->second++;
                }
                //없으니까 새로만들기
                else {
                    map.emplace(MinusCounter(abs(value), 1));
                }
                heap.push(abs(value));
            }
            else {
                heap.push(value);
            }
        }
    }

    for (const auto& i : printVector) { 
        std::cout << i << "\n";
    }

}