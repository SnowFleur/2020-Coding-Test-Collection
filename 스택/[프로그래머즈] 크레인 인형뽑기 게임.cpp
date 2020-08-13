#include<iostream>
#include<vector>
#include <string>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    //Stack 형식으로 재배열
    std::vector<std::stack<int>> stackBoard(board.size());
    for (int j = 0; j < board.size(); ++j) {
        for (int i = board.size() - 1; i >= 0; --i) {
            if(board[i][j]!=0)
            stackBoard[j].push(board[i][j]);

        }
    }

    //넣을 스텍
    std::stack<int> s;

    // 포인터는 해당 스텍을 가리키는 포인터이며
    // FIFO 특성을 가진 Stack을 이용하여 배열에 넣는다.
    for ( auto& pointer : moves) {
        //index와 호환을 위한 -1
        pointer -= 1;

        if (stackBoard[pointer].empty())
            continue;

        auto topValue = stackBoard[pointer].top();
        stackBoard[pointer].pop();

        //스텍이 비어있는 상태가 아니고 현재 스텍과 넣을 값이 같다면 터트리고 +=2
        if (s.empty() == false && s.top() == topValue) {
            s.pop();
            answer += 2;
        }
        //아니라면 그냥 스텍에 넣는다.
        else {
            s.push(topValue);
        }
    }

    return answer;
}


int main() {
    vector<vector<int>> board(5,std::vector<int>(5));
    
    board[0] = { 0,0,0,0,0 };
    board[1] = { 0,0,1,0,3 };
    board[2] = { 0,2,5,0,1 };
    board[3] = { 4,2,4,4,2 };
    board[4] = { 3,5,1,3,1};


    vector<int> moves(8);

    moves[0] = 1;
    moves[1] = 5;
    moves[2] = 3;
    moves[3] = 5;
    moves[4] = 1;
    moves[5] = 2;
    moves[6] = 1;
    moves[7] = 4;
    std::cout<<solution(board, moves);
}