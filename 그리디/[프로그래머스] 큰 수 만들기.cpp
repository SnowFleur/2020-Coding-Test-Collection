#include <string>
using namespace std;
string solution(string number, int k) {
    int count = k;
    //K��ŭ �ݺ����� ���� ������������ ã�´�.
    for (int i = 0; i < k; ++i) {

        //����� ������ ���ؼ� ���簡 �� ��������� ����
        for (int i = 0; i < number.size() - 1; ++i) {

            //�������� �� ũ�ϱ� ����
            if (number[i] < number[i + 1]) {

                //ã�� ������
                number.erase(i, 1);
                --count;
                break;
            }
        }
    }

    //���� ó�� �׽�Ʈ ���̽�(12)
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