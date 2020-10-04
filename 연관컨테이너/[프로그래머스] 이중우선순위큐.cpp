#include <string>
#include <vector>
#include<set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int,std::greater<int>> set;
    for (auto& oper : operations) {
        //Queue�� ����
        if (oper[0] == 'I') {
            oper.erase(0, 2);
            set.emplace(atoi(oper.c_str()));
        }

        //Queue�� �ִ밪 Ȥ�� �ּڰ� ����
        else if (oper[0] == 'D' && set.empty()==false) {
            //�ּڰ� ����
            if (oper[2] == '-') {
                //���� �ڿ��ִ� ���� ���� ������
                auto iter = --set.end();
                set.erase(iter);
            }
            //�ִ밪 ����
            else {
                set.erase(set.begin());
            }
        }
    }

    if (set.size() == 0) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    else {
        answer.emplace_back(*(set.begin()));
        answer.emplace_back(*(--set.end()));
    }
    return answer;
}


int main() {

    //vector<string> operations = { "I 16","D 1"};
    vector<string> operations = { "I 7","I 5","I - 5","D - 1" };
    solution(operations);

}
