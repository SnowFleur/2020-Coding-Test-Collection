#include<iostream>

#include <vector>
#include<utility>
#include<queue>

constexpr int STRATE_COST   = 100;
constexpr int CURVE_COST    = 600;
constexpr int BOARD_SIZE    = 26;
constexpr int MAX_COST      = 9999999;
using Direction = std::pair<int, int>;

class CNode {
public:
    int         constructCost_;
    int         x_;
    int         y_;
    int         dir_;
};

int costed[BOARD_SIZE][BOARD_SIZE];
std::queue<CNode> queue;

int solution(std::vector<std::vector<int>> board) {
    int answer = MAX_COST;
    int goal = board.size() - 1;
    Direction direction[4] = { 
        Direction{-1,0},Direction{0,-1},
        Direction{1,0}, Direction{0,1} };

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            costed[i][j] = MAX_COST;
        }
    }

    queue.emplace(CNode{ 0,0,0,-1 });
    //BFS
    while (queue.empty() == false) {
        int x = queue.front().x_;
        int y = queue.front().y_;
        int cost = queue.front().constructCost_;
        int dir = queue.front().dir_;

        queue.pop();

        if (x == goal && y == goal) {
            if (answer >= cost) {
                answer = cost;
            }
        }

        //Search(Left, Right, Down, Top)
        for (int i = 0; i < 4; ++i) {

            int dx = x + direction[i].first;
            int dy = y + direction[i].second;

            //Safe Check
            if ( (dx >= 0 && dx < board.size()) && (dy >= 0 && dy < board.size())) {

                //Move Able
                if (board[dx][dy] == 0) {

                    int newCost;
                    

                    //같은 방향
                    if ((i % 2) == (dir % 2) || dir == -1) {
                        newCost = cost + STRATE_COST;
                    }
                    else {
                        newCost = cost + CURVE_COST;
                    }

                    if (newCost <= costed[dx][dy]) {
                        costed[dx][dy] = newCost;
                        queue.emplace(CNode{ newCost,dx,dy,i });
                    }
                }
            }
        }
    }
    return answer;
}


int main() {
  /*  std::vector<std::vector<int>> board{
        {0,0,0 },
        { 0,0,0 },
        { 0,0,0 } };*/

    std::vector<std::vector<int>> board{
    {0,0,0,0,0,0,0,1},
    { 0,0,0,0,0,0,0,0 },
    {0,0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0,0},
    {0,0,0,1,0,0,0,1},
    {0,0,1,0,0,0,1,0},
    {0,1,0,0,0,1,0,0},
    {1,0,0,0,0,0,0,0},
    };

    /* std::vector<std::vector<int>> board{
       {0,0,1,0 },
       {0,0,0,0 },
       {0,1,0,1 },
       {1,0,0,0} };*/

         //std::vector<std::vector<int>> board{
         //    {0,0,0,0,0,0},
         //    {0,1,1,1,1,0 },
         //    {0,0,1,0,0,0 },
         //    {1,0,0,1,0,1},
         //    {0,1,0,0,0,1} ,
         //    {0,0,0,0,0,0} };


    std::cout << solution(board) << "\n";
}


