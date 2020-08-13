#include<iostream>
#include<string>
#include<cstring>
#include<vector>

int main() {
    std::string N{};
    std::vector<char> vector;
    int minimumCount{ 0 };

    std::cin >> N;
    for (auto& word : N)
        vector.emplace_back(word);

    // 1 Set(0~9)
    bool setList[10]{ false };

    while (vector.size() != 0) {

        //One Cycle
        for (auto iter = vector.begin(); iter != vector.end();) {
            int number = *iter - '0';

            //6<--->9 예외처리
            if (number == 6 || number == 9) {
                if (!(setList[6] && setList[9])) {
                    if (setList[6] == false) {
                        setList[6] = true;
                    }
                    else {
                        setList[9] = true;
                    }
                    iter = vector.erase(iter);
                    continue;
                }
            }

            if (setList[number] == false) {
                setList[number] = true;
                iter = vector.erase(iter);
            }
            else {
                ++iter;
            }
        }
        ++minimumCount;
        memset(setList, false, sizeof(setList));
    }
    std::cout << minimumCount << "\n";
}