#include<iostream>
#include<array>
#include<algorithm>
int main() {
	std::array<int,4>position;
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;
	position[0] = x, position[1] = y;  //���� �Ʒ� �������� 0,0�̱� ������ �״�� ���� �ִ´�.
	position[2] = w - x, position[3] = h - y; //������ �������� ��ġ�� ���Ѵ�.
	std::cout << *(std::min_element(position.cbegin(), position.cend())) << std::endl;
	system("pause");
}

