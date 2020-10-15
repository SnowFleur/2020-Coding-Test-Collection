#include<iostream>
#include<vector>
#include<algorithm>
constexpr int MAX_LANGE = 99999999;

int main() {
    int N{ 0 }, S{ 0 };
    std::vector<int> v;
    std::cin >> N >> S;

    int value{ 0 };
    for (int i = 0; i < N; ++i) {
        std::cin >> value;
        v.emplace_back(value);
    }

    int minLange{ MAX_LANGE }, left{ 0 }, right{ 0 }, total{ 0 };

    total = v[right];
    while (true) {

        //합계가 더 크다면 left 증가
        if (total >= S) {
            minLange = std::min(minLange, right - left + 1);
            total = total - v[left++];
        }

        //합계가 더 작다면 right 증가
        else {
            right++;
            if (right == N) {
                break;
            }

            total = total + v[right];
        }
    }

    if (minLange == MAX_LANGE)
        std::cout <<0;
    else
        std::cout << minLange;

}