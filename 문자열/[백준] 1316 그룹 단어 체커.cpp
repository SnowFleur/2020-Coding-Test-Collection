#include<iostream>
#include<regex>
#include<string>
#include<vector>


/*
1. a-z�迭�� �����.
2. ó�������°� ����ó��
3. �ϳ��� �ε����� �������Ѽ� �� ���� �� �� �������� ����.

*/

int CheckGroupWord(std::vector<std::string>& words) {
    int result{ 0 };
    for (const auto& word : words) {

        std::pair<int, bool> alphabet[26] = { std::pair<int,bool>(0,false) };
        int alphabetIndex{ 0 };
        bool isGroup{ true };

        for (const auto& ch : word) {
            int index{ ch - 'a' };
            //�� ���ĺ��� ó�� ���Դٸ�
            if (alphabet[index].second == false) {
                alphabet[index].second = true;
                alphabet[index].first = alphabetIndex++;
            }
            //�̹� ���� ���� �ִ� ���ĺ��̶��
            //���� �� �� ���̰� ������ ����.
            else {
                //�� �� ���̶�� �ٷ� ���� ���� ���̱� ������ ������ ����.
                if (alphabet[index].first== alphabetIndex-1) {
                    alphabet[index].first = alphabetIndex++;
                }
                else {
                //������ �߻��ߴ�
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