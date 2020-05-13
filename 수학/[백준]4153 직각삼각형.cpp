#include<iostream>
int main() {
	int a, b, c;
	for (; true;) {
		std::cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)break;

			if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a)) {
				std::cout << "right" << std::endl;
			}
			else
				std::cout << "wrong" << std::endl;
	}
}