#include<iostream>
#include<vector>
/*
N: 1���� N����
M: �ߺ��� ���� ����
*/
int g_N, g_M;
std::vector<int> g_v;
std::vector<bool> g_visited;

void BackTracking(int curr) {

	//curr�� 4�̸� ���
	if (curr > g_M) {
		for (const auto& i : g_v)
			std::cout << i << " ";
		std::cout << "\n";
		return;
	}

	//�ݺ����� ����Ѵ� 
	for (int i = 1; i <= g_N; ++i) {

		//�����尡 true�� �ƴϸ� ����. true�̸� �̹� �湮�ߴ�.
		if (g_visited[i] != true) {
			g_visited[i] = true; 
			g_v.emplace_back(i);
			BackTracking(curr + 1); //ī���͸� ������Ų��.
			g_v.pop_back();
			//���� �� ���ƿ��� �κ�
			g_visited[i] = false;
		}
	}
}


int main() {
	std::cin >> g_N >> g_M;
	g_visited.assign(g_N + 1, false);
	BackTracking(1); //0���� ����
}

