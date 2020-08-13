#include<iostream>

using Time =  int;
constexpr int ALARM = 45;

void CheckHour(Time& h) {

    if (h == 0) {
        h = 23;
    }
    else {
        --h;
    }
}

void CheckTIme(Time& h, Time& m) {

    if (m - ALARM < 0) {
        CheckHour(h);
        m = 60 + (m - ALARM);
    }
    else {
        m -= ALARM;
    }
}

int main() {
    Time H, M;
    std::cin >> H >> M;

    CheckTIme(H, M);
    std::cout << (int)H << " " << (int)M << "\n";


}