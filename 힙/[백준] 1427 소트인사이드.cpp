#include<iostream>
#include<queue>
#include<string>

int main() {
    std::string s;
    std::priority_queue<char> queue;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        queue.emplace(s[i]);
    }

    while (queue.empty() == false) {
        std::cout << queue.top();
        queue.pop();
    }
}