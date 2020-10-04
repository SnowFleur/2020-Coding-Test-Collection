#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<stdio.h>

using topPairData = std::pair<int, int>; //height, receive

int main() {
    int N{};
    scanf("%d",&N);
    std::stack<topPairData>tops;
    int currentHeight{};
    for (int i = 0; i < N; ++i) {
        topPairData pairData;
        scanf("%d", &pairData.second);

        pairData.first = i+1;

        while (tops.empty() == false) {

            auto top = tops.top();

            // 현재 탑보다 height가 크다면 0 출력
            if (top.second < pairData.second) {
                tops.pop();
            }
            //현재 탑이 더 크다면 수신
            else {
                printf("%d ",top.first);
                tops.push(pairData);
                break;
            }
        } //while end

        if (tops.empty()) {
            printf("0 ");
            tops.push(pairData);
        }
    }
}


/*
Input
6
6 4 5 2 5 1

Output
Wrong
0 1 1 3 2 5

Correct
0 1 1 3 3 5


Input
5
6 9 5 10 4
Output
0 0 2 2 4
Answer
0 0 2 0 4
*/