#include<iostream>
#include<vector>
/*
N: 1부터 N까지
M: 중복이 없는 수열
*/
int g_N, g_M;
std::vector<int> g_v;
std::vector<bool> g_visited;

void BackTracking(int curr) {

	//curr이 4이면 출력
	if (curr > g_M) {
		for (const auto& i : g_v)
			std::cout << i << " ";
		std::cout << "\n";
		return;
	}

	//반복문을 사용한다 
	for (int i = 1; i <= g_N; ++i) {

		//현재노드가 true가 아니면 돈다. true이면 이미 방문했다.
		if (g_visited[i] != true) {
			g_visited[i] = true; 
			g_v.emplace_back(i);
			BackTracking(curr + 1); //카운터를 증가시킨다.
			g_v.pop_back();
			//리턴 후 돌아오는 부분
			g_visited[i] = false;
		}
	}
}


int main() {
	std::cin >> g_N >> g_M;
	g_visited.assign(g_N + 1, false);
	BackTracking(1); //0부터 시작
}

