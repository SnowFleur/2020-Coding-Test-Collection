#include<iostream>
#include<vector>

constexpr int MAX_SET = 28;

std::vector<std::vector<int>>S;
std::vector<int>V;
int K{};
bool visited[MAX_SET];

void BackTracking(int curr, int index) {

    if (curr > 6) {
        for (const auto& i : V) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < S[index].size(); ++i) {
        //�湮���ΰ� false�̸� �������� üũ����
        if (visited[i] == false) {

            //�������� �Ҷ� �տ� ���ڰ� �� ������ �н�
            if (V.size() != 0) {
                if (S[index][i] < V[V.size() - 1])continue;
            }

            V.emplace_back(S[index][i]);
            visited[i] = true;
            BackTracking(curr + 1, index);
            //BackTracking ����
            V.pop_back();
            visited[i] = false;

        }
    }
}

int main() {

    while (true) {
        std::cin >> K;
        std::vector<int>setLIst;
        if (K == 0)break;


        for (int i = 0; i < K; ++i) {
            int number{};
            std::cin >> number;
            setLIst.emplace_back(std::move(number));
        }
        S.emplace_back(setLIst);

    }
    for (int i = 0; i < S.size(); ++i) {
        BackTracking(1, i);
        std::cout << "\n";
    }
}