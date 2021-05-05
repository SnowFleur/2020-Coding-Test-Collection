#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>

using Data = std::pair<size_t, size_t>; //����Ƚ��, �ܾ����
using VectorData = std::tuple<std::string, size_t, size_t>; //�ܾ�, ���� Ƚ��, �ܾ����

int main() {
    int N{}, M{};
    std::cin >> N >> M;
    std::map<std::string, Data> book;
    std::vector< VectorData> printVector;

    for (int i = 0; i < N; ++i) {
        std::string s;
        std::cin >> s;
        if (s.size() < M)continue;

        book[s].first++;
        book[s].second = s.size();
    }

    for (const auto& i : book) {
        printVector.emplace_back(VectorData{ i.first,i.second.first,i.second.second });
    }

    auto cmp = [](const VectorData& lhs, const VectorData& rhs) {

        //1. ���� ������ �ܾ�
        if (std::get<1>(lhs) > std::get<1>(rhs)) {
            return true;
        }
        else if (std::get<1>(lhs) == std::get<1>(rhs)) {
            //2. �ܾ��� ����
            if (std::get<2>(lhs) > std::get<2>(rhs)) {
                return true;
            }
            //3. ���ĺ� ������
            else if (std::get<2>(lhs) == std::get<2>(rhs)) {
                return std::get<0>(lhs) < std::get<0>(rhs);
            }
        }
        return false;
    };

    std::sort(printVector.begin(), printVector.end(), cmp);

    for (const auto& i : printVector)
        std::cout << std::get<0>(i) << "\n";

}
