#include<iostream>
using namespace std;
constexpr int LIMIT_CYCLE = 500;

//Collaztz Law
int solution(int num) {
    int answer = -1;
    long long llnum = num;

    if (llnum == 1)
        return 0;

    for (int i = 0; i < LIMIT_CYCLE; ++i) {

        //1-1 �Էµ� ���� ¦����� 2�� ������.
        if (llnum % 2 == 0) {
            llnum /= 2;
        }
        //1-2 �Էµ� ���� Ȧ����� 3�� ���ϰ� 1�� ���Ѵ�.
        else {
            llnum = llnum * 3 + 1;
        }
        //2 ����� ���� ���� ���� �۾��� 1�� �� �� ���� �ݺ�(500)
        if (llnum == 1) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}


//-1
int main() {

    std::cout << solution(626331) << "\n";
}


