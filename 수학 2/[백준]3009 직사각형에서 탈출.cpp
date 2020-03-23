#include<iostream>
#include<array>
#include<algorithm>
int main() {
	std::array<int,4>position;
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;
	position[0] = x, position[1] = y;  //왼쪽 아래 꼭지점이 0,0이기 때문에 그대로 값을 넣는다.
	position[2] = w - x, position[3] = h - y; //오른쪽 꼭지점의 위치를 구한다.
	std::cout << *(std::min_element(position.cbegin(), position.cend())) << std::endl;
	system("pause");
}

