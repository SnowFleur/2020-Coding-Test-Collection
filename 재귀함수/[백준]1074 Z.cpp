#include<iostream>
int g_number;
int N = 0, g_x = 0, g_y = 0;
// r,c�� �� ��° �湮�ϴ°�?
void Function(int N, int row, int col) {
	//���� �������� ������.
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
	Function(N / 2, row, col); //���� 
	Function(N / 2, row, col + N / 2); //������
	Function(N / 2, row + N / 2, col);//���ʾƷ�
	Function(N / 2, row + N / 2, col + N / 2);//������ �Ʒ�
}

int main() {
	std::cin >> N >> g_x >> g_y;
	Function(1<<N, 0, 0);
}