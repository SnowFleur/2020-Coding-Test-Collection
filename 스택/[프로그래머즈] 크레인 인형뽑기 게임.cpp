#include<iostream>
#include<vector>
#include <string>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    //Stack �������� ��迭
    std::vector<std::stack<int>> stackBoard(board.size());
    for (int j = 0; j < board.size(); ++j) {
        for (int i = board.size() - 1; i >= 0; --i) {
            if(board[i][j]!=0)
            stackBoard[j].push(board[i][j]);

        }
    }

    //���� ����
    std::stack<int> s;

    // �����ʹ� �ش� ������ ����Ű�� �������̸�
    // FIFO Ư���� ���� Stack�� �̿��Ͽ� �迭�� �ִ´�.
    for ( auto& pointer : moves) {
        //index�� ȣȯ�� ���� -1
        pointer -= 1;

        if (stackBoard[pointer].empty())
            continue;

        auto topValue = stackBoard[pointer].top();
        stackBoard[pointer].pop();

        //������ ����ִ� ���°� �ƴϰ� ���� ���ذ� ���� ���� ���ٸ� ��Ʈ���� +=2
        if (s.empty() == false && s.top() == topValue) {
            s.pop();
            answer += 2;
        }
        //�ƴ϶�� �׳� ���ؿ� �ִ´�.
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