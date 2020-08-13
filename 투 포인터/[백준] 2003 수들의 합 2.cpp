#include<iostream>
#include<vector>

constexpr long long max_n = 1001;
constexpr long long  max_m = 300000001;
/*
1. 왼쪽 오른쪽 0
2. 현재 부분합 m이 같다면 ++카운터
3. 현재 부분합이 m보다 작거나 같다면 ++오른쪽
4. 현재 부분합이 m보다 크다면 ++왼쪽
5. 모든 경우를 확인할 때까지 2~4반복
*/
int twopointer(long long m, std::vector<long long>& v) {

    long long leftpointer{}, rightpoint{};
    long long result{};
    long long sum{};

    while(leftpointer<v.size()) {

        // sum이 m보다 작으니까 계속  right 증가시켜보자
        while (sum<m  && rightpoint<v.size()){
            sum += v[rightpoint];
            ++rightpoint;
        }

        //같으면 결과 증가
        if (sum == m)
            ++result;
        sum -= v[leftpointer];
        ++leftpointer;
    }
    return result;
}

int main() {
    long long n{}, m{};
    std::cin >> n >> m;
    std::vector<long long> v;
    for (long long i = 0; i < n; ++i) {
        long long number{};
        std::cin >> number;
        v.emplace_back(number);
    }
    std::cout << twopointer(m, v) << "\n";
}
