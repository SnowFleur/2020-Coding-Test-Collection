#include<iostream>
#include<string>
#include<array>
constexpr int ALPHABET_LENGTH = 26;

int main() {
    std::array<int, ALPHABET_LENGTH>alphabetList{};
    std::string word;

    std::cin >> word;

    for (const auto& s : word) {
        int index = toupper(s) - 'A';

        alphabetList[index]++;

    }

    for (const auto& i : alphabetList)
        std::cout << i << " ";


}