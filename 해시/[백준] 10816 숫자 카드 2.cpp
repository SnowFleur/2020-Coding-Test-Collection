#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<stdio.h>
int main() {
    int N{}, M{};
    int value{};
    std::unordered_map<int,int>numberCards;
    
    /*
    N: ����ī�� ����
    */
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &value);

        numberCards[value]++;
    }

    /*
    M: ������ �ִ� ī�尳��
    */
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &value);
        printf("%d ", numberCards[value]);
    }

}