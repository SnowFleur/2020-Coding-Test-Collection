#include<iostream>

int main() {
    int N{}, count{};
    std::cin >> N;

    int left{}, right{}, total{};
    total = 1;
    left = 1;
    right = 2;

    while (left <= N) {

        total = total + right;

        //������ ���̶�� count ����
        if (total == N) {
            ++count;
            total = 0;
            ++left;
            right = left;
        }
        //total ���� �� Ŀ������ Left�� �����ϰ� �ٽý���
        else if (total > N) {
            ++left;
            total = 0;
            right = left;
        }
        else {
            ++right;
        }
    }
    std::cout << count << "\n";
}

