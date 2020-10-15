#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<algorithm>

using Position = std::pair<double, double>;

int GetScore(std::vector<Position>& player) {
    int sum{ 0 };
    //3번 진행
    for (int i = 0; i < 3; ++i) {
        //두 점사이의 거리( 원점은 0,0이기 때문에 곱셈만 진행)
      /*  double len = sqrt((player[i].first * player[i].first) +
            (player[i].second * player[i].second));*/

        double len = abs((player[i].first * player[i].first) +
            (player[i].second * player[i].second));

        if (len <= 3) {
            sum += 100;
        }
        else if (len <= 6) {
            sum += 80;
        }
        else if (len <= 9) {
            sum += 60;
        }
        else if (len <= 12) {
            sum += 40;
        }
        else if (len <= 15) {
            sum += 20;
        }
    }
    return sum;
}

int main() {
    int testCase{};
    std::cin >> testCase;

    //Test Case 까지
    for (int i = 0; i < testCase; ++i) {
        std::vector<Position> v;
        std::vector<Position> player1;
        std::vector<Position> player2;
        //2번씩 6번
        for (int j = 0; j < 6; ++j) {
            Position p;
            std::cin >> p.first >> p.second;
            v.emplace_back(p);
        }


        //0~3까지는 플레이어1
        std::copy(v.begin(), v.begin() + 3, std::back_inserter(player1));
        //4~6까지는 플레이어2
        std::copy(v.begin() + 3, v.end(), std::back_inserter(player2));

        int player1Score = GetScore(player1);
        int player2Score = GetScore(player2);

        std::cout << "SCORE: " << player1Score << " to " << player2Score << ", ";
        if (player1Score == player2Score) {
            std::cout << "TIE.\n";
        }
        else if (player1Score > player2Score) {
            std::cout << "PLAYER 1 WINS.\n";
        }
        else {
            std::cout << "PLAYER 2 WINS.\n";
        }

    } //end TestCase For

}
