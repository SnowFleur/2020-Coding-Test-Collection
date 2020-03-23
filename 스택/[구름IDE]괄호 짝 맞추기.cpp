#include<iostream>
#include<stack>

using namespace std;
bool Soluction(char*);

int main() {
	char input[100];
	cin >> input;

	//까다로운 입출력방식
	if (Soluction(input)) {

		std::cout << "True" << std::endl;
	}
	else
		std::cout << "False" << std::endl;

	return 0;
}

bool Soluction(char* input) {
	stack<char>my_stack;
	for (size_t i = 0; input[i] != '\0'; ++i) {
		// 오른쪽은 pop
		// 왼쪽은 push

		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
			my_stack.push(input[i]);

		else if (input[i] == ')' && !my_stack.empty()) {
			if (my_stack.top() == '(')
				my_stack.pop();
			else return 0;
		}

		else if (input[i] == '}' && !my_stack.empty()) {
			if (my_stack.top() == '{')
				my_stack.pop();
			else return 0;

		}

		else if (input[i] == ']' && !my_stack.empty()) {
			if (my_stack.top() == '[')
				my_stack.pop();
			else return 0;

		}
		else
			return 0;

	}

	return my_stack.empty();

}
