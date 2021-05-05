#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool ChekInValid(int ch) {

    //If 중 하나라도 해당되면 false
    bool invalid{ true };

    if ('a' <= ch && ch <= 'z')invalid = false;
    if ('0' <= ch && ch <= '9')invalid = false;
    if ('.'== ch)invalid = false;
    if ('_' == ch || ch == '-') invalid = false;
    return invalid;
}

string solution(string new_id) {
    string answer = "";

    //1단계 
    for (int i = 0; i < new_id.size(); ++i) {
        auto temp = std::tolower(new_id[i]);
        //2단계 
        if (ChekInValid(temp) == false) {
            answer.push_back(temp);
        }

    }

    //3단계
    answer.erase(std::unique(answer.begin(), answer.end(), [](const auto& lhs, const auto& rhs) {

        if (lhs == '.' && rhs == '.')
            return true;
        return false;
    }),answer.end());


    //4단계
    if (*answer.begin() == '.')
        answer.erase(answer.begin());
    if (*(answer.end() - 1) == '.') {
        answer.erase(answer.end() - 1);
    }


    //5단계
    if (answer.size() == 0) {
        answer.push_back('a');
    }

    //6단계
    if (answer.size() >= 16) {
        answer.erase(answer.begin() + 15, answer.end());

        if(*(answer.end()-1)== '.')
            answer.erase(answer.end() - 1);
    }

    //7단계
    if (answer.size() <= 2) {
        auto lastWord = *(answer.end() - 1);
        while (answer.size() != 3) {
            answer.push_back(lastWord);
        }
    }

    return answer;
}
