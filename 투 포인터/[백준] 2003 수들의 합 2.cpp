#include<iostream>
#include<vector>

constexpr long long max_n = 1001;
constexpr long long  max_m = 300000001;
/*
1. ���� ������ 0
2. ���� �κ��� m�� ���ٸ� ++ī����
3. ���� �κ����� m���� �۰ų� ���ٸ� ++������
4. ���� �κ����� m���� ũ�ٸ� ++����
5. ��� ��츦 Ȯ���� ������ 2~4�ݺ�
*/
int twopointer(long long m, std::vector<long long>& v) {

    long long leftpointer{}, rightpoint{};
    long long result{};
    long long sum{};

    while(leftpointer<v.size()) {

        // sum�� m���� �����ϱ� ���  right �������Ѻ���
        while (sum<m  && rightpoint<v.size()){
            sum += v[rightpoint];
            ++rightpoint;
        }

        //������ ��� ����
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
