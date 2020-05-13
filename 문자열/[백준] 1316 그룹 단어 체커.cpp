#include<iostream>
#include<regex>
#include<string>
#include<vector>


/*
1. a-z배열을 만든다.
2. 처음나오는건 예외처리
3. 하나씩 인덱스를 증가시켜서 그 전과 비교 후 다음인지 본다.

*/

int CheckGroupWord(std::vector<std::string>& words) {
    int result{ 0 };
    for (const auto& word : words) {

        std::pair<int, bool> alphabet[26] = { std::pair<int,bool>(0,false) };
        int alphabetIndex{ 0 };
        bool isGroup{ true };

        for (const auto& ch : word) {
            int index{ ch - 'a' };
            //이 알파벳이 처음 나왔다면
            if (alphabet[index].second == false) {
                alphabet[index].second = true;
                alphabet[index].first = alphabetIndex++;
            }
            //이미 나온 적이 있는 알파벳이라면
            //값이 한 개 차이가 나는지 본다.
            else {
                //한 개 차이라면 바로 전에 들어온 거이기 때문에 문제가 없다.
                if (alphabet[index].first== alphabetIndex-1) {
                    alphabet[index].first = alphabetIndex++;
                }
                else {
                //문제가 발생했다
                    isGroup = false;
                    break;
                }
            }
        }
        if (isGroup)
            ++result;
    }
    return result;
}

int main() {
    std::string word;
    std::vector<std::string>words;
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> word;
        words.push_back(word);
    }
    std::cout << CheckGroupWord(words);

}