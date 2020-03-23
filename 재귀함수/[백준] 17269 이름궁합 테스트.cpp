#include<iostream>
#include<vector>
#include<map>

void RecursiveFun(std::vector<int>& v,int index);
int main() {
	std::map<char, int>alphaList{
		{'A',3},{'B',2},{'C',1},{'D',2},{'E',4},{'F',3},{'G',1},
		{'H',3},{'I',1},{'J',1},{'K',3},{'L',1},{'M',3},{'N',2},
		{'O',1},{'P',2},{'Q',2},{'R',2},{'S',1},{'T',2},{'U',1},
		{'V',1},{'W',1},{'X',2},{'Y',2},{'Z',1}};

	std::string left_name{};
	std::string right_name{};
	std::string merge_name{};
	int N, M;
	std::cin >> N >> M;
	std::cin >> left_name >> right_name;

	int left_index{}, right_index{};
	bool shift = false;

	while(true){
		if (shift==false) {
			if (left_name[left_index] == '\0') {
				
				while(right_name[right_index]!='\0')
					merge_name += right_name[right_index++];
				break;
			}
			merge_name += left_name[left_index++];

		}
		else {
			if (right_name[right_index] == '\0') {

				while (left_name[left_index] != '\0')
					merge_name += left_name[left_index++];
				break;
			}
			merge_name += right_name[right_index++];
		}
		shift = true - shift;
	}

	//vector init
	std::vector<int> v;
	for (auto i : merge_name) {
		v.emplace_back(alphaList[i]);
	}
	RecursiveFun(v,1);
}

void RecursiveFun(std::vector<int>& v,int index) {

	if (v.size() - index == 1) {
		std::cout << (v[0] * 10) + v[1]<<"% \n";
		return;
	}

	for (int i = 0; i < v.size()-index; ++i) {
		v[i] = (v[i] + v[i + 1])%10;
	}

	RecursiveFun(v, ++index);
}