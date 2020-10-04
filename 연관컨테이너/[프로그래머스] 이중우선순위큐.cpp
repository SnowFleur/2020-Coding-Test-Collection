#include <string>
#include <vector>
#include<set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int,std::greater<int>> set;
    for (auto& oper : operations) {
        //Queue에 삽입
        if (oper[0] == 'I') {
            oper.erase(0, 2);
            set.emplace(atoi(oper.c_str()));
        }

        //Queue의 최대값 혹은 최솟갑 삭제
        else if (oper[0] == 'D' && set.empty()==false) {
            //최솟값 삭제
            if (oper[2] == '-') {
                //가장 뒤에있는 값이 가장 작은값
                auto iter = --set.end();
                set.erase(iter);
            }
            //최대값 삭제
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
