#include<iostream>
#include<algorithm>
#include<vector>

int main() {
    std::vector<int> v;
    std::vector<int> L(1000000, 0);

    int  N{};
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int value{};
        std::cin >> value;
        v.emplace_back(value);
    }

    for (auto& here : v) {
        //L이 비어있거나 마지막 원소보다 here가 큰경우
        if (L.empty()) {
            L.emplace_back(here);
        }

        else if (*(L.end() - 1) < here) {
            L.emplace_back(here);
        }
        //그렇지 않은경우
        else {
            auto iter = std::lower_bound(L.begin(), L.end(), here);
            L[iter - L.begin()] = here;
        }
    }
    std::cout << L.size() << "\n";
}