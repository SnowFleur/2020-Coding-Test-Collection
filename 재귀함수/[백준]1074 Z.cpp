#include<iostream>
int g_number;
int N = 0, g_x = 0, g_y = 0;
// r,c를 몇 번째 방문하는가?
void Function(int N, int row, int col) {
	//작은 단위까지 나눈다.
	if (N == 2) {
		// 0,0
		if (g_x == row && g_y == col) {
			std::cout << g_number << "\n";
			return;
		}
		++g_number;
		//0,1
		if (g_x == row && g_y == col + 1) {
			std::cout << g_number << "\n";
			return;
		}
		++g_number;
		// 1,0
		if (g_x == row + 1 && g_y == col) {
			std::cout << g_number << "\n";
			return;
		}
		++g_number;
		//1,1
		if (g_x == row + 1 && g_y == col + 1) {
			std::cout << g_number << "\n";
			return;
		}
		++g_number;
		return;
	}
	Function(N / 2, row, col); //왼쪽 
	Function(N / 2, row, col + N / 2); //오른쪽
	Function(N / 2, row + N / 2, col);//왼쪽아래
	Function(N / 2, row + N / 2, col + N / 2);//오른쪽 아래
}

int main() {
	std::cin >> N >> g_x >> g_y;
	Function(1<<N, 0, 0);
}