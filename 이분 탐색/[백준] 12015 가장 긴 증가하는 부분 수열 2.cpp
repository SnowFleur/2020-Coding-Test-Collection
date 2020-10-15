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
        //L�� ����ְų� ������ ���Һ��� here�� ū���
        if (L.empty()) {
            L.emplace_back(here);
        }

        else if (*(L.end() - 1) < here) {
            L.emplace_back(here);
        }
        //�׷��� �������
        else {
            auto iter = std::lower_bound(L.begin(), L.end(), here);
            L[iter - L.begin()] = here;
        }
    }
    std::cout << L.size() << "\n";
}