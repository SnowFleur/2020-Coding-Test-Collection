#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>

int main() {
    //M: 문제의 개수
    //N: 포켓몬의 개수
    int M{}, N{};
    std::cin >> N >> M;

    std::map<std::string,std::string> PokemonIndex;
    //출력용 Vector
    std::vector <std::string> printVector;

    /*
    Insert Data
    */
    for (int i = 0; i < N; ++i) {
        std::stringstream index{};
        std::string name{};
        std::cin >> name;
        index << (i+1);

        PokemonIndex.emplace(name, index.str());
        PokemonIndex.emplace(index.str(), name);
    }

    std::string answer{};
    for (int i = 0; i < M; ++i) {
        std::cin >> answer;
        printVector.emplace_back(PokemonIndex.find(answer)->second);
    }

    for (const auto& i : printVector) {
        std::cout << i << "\n";
    }

}