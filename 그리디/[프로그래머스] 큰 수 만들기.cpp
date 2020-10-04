#include <string>
using namespace std;
string solution(string number, int k) {
    int count = k;
    //K만큼 반복문을 돌며 내림차순으로 찾는다.
    for (int i = 0; i < k; ++i) {

        //현재와 다음을 비교해서 현재가 더 작은수라면 삭제
        for (int i = 0; i < number.size() - 1; ++i) {

            //다음값이 더 크니까 삭제
            if (number[i] < number[i + 1]) {

                //찾은 값삭제
                number.erase(i, 1);
                --count;
                break;
            }
        }
    }

    //예외 처리 테스트 케이스(12)
    if (count != 0) {
        for (int i = 0; i < count; ++i) {
            number.pop_back();
        }
        return number;
    }
    return number;
}

#include<iostream>

int main() {
    std::cout << solution("1231234", 3) << "\n";
    /*

    std::cout << solution("1924", 2) << "\n";
    std::cout << solution("4177252841", 4) << "\n";
    std::cout << solution("1111", 2) << "\n";

    */
    //std::cout << solution("99991", 3) << "\n";




}