#include<iostream>
#include<set>
int main() {

    //입출력 속도 상승
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::multiset<int> set;
    std::cin >> N >> M;
    

    for (int i = 0; i < N; ++i) {
        int value;
        std::cin >> value;
        set.insert(value);
    }
    for (int i = 0; i < M; ++i) {
        int value;
        std::cin >> value;
        set.insert(value);
    }


    for (const auto& i : set)
        std::cout << i <<" ";
}