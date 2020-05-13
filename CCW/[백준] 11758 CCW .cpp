#include<iostream>

struct Point {
private:
public:
	int x;
	int y;
};

int CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}


int main() {
	Point P1, P2, P3;

	std::cin >> P1.x >> P1.y;
	std::cin >> P2.x >> P2.y;
	std::cin >> P3.x >> P3.y;


	int result = CCW(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y);

	if (result == 0) {
		std::cout << 0 << "\n";
	}
	else if (result > 0) {
		std::cout << 1 << "\n";

	}
	else {
		std::cout << -1 << "\n";
	}

}