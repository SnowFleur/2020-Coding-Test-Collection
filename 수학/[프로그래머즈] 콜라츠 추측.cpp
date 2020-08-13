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

        //1-1 입력된 수가 짝수라면 2로 나눈다.
        if (llnum % 2 == 0) {
            llnum /= 2;
        }
        //1-2 입력된 수가 홀수라면 3을 곱하고 1을 더한다.
        else {
            llnum = llnum * 3 + 1;
        }
        //2 결과로 나온 수에 같은 작업을 1이 될 때 까지 반복(500)
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


