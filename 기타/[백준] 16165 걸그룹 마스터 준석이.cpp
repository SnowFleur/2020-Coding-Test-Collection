#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

constexpr int TOTAL_GROUP	= 100;
constexpr int TOTAL_PROBLEM = 100;

using groups_pair = std::pair < std::string, std::vector<std::string>>;
using members_pair = std::pair < std::string, std::string>;

std::map<std::string, std::vector<std::string>>		g_members;
std::map<std::string, std::string>					g_groups;

std::vector<std::string>							g_solution;


// map�� �ɱ׷� ������ �ִ´�.
void InsertGroupInfor() {
	int total_member{};
	std::string group_name{};
	std::string member_name{};
	std::vector<std::string>group_members;

	std::cin >> group_name;
	std::cin >> total_member;

	for (int i = 0; i < total_member; ++i) {
		std::cin >> member_name;
		group_members.emplace_back(member_name);
		//�ش� ����� �׷� ������ �ִ´�.
		g_groups.emplace(members_pair{ member_name,group_name });  
	}
	//�ش� �׷��� ������� ������ �ִ´�.
	g_members.emplace(groups_pair(group_name, group_members));

}

// map�� �ִ� ������ ���� ���� ã�´�.
void ProcessProblumes() {
	int select{};  
	std::string name{};
	std::cin >> name;
	std::cin >> select;

	//0-> DisPlay All member 
	if (select == 0) {
		auto iter = g_members.find(name)->second;
		std::sort(iter.begin(), iter.end(), [](const auto& lhs, const auto& rhs) {return lhs < rhs; });
		std::copy(iter.begin(), iter.end(), std::back_inserter(g_solution));
	}
	// 1-> DisPlay Team
	else {
		auto iter = g_groups.find(name)->second;
		g_solution.emplace_back(iter);
	}

}

int main() {
	int N{}, M{};
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
		InsertGroupInfor();

	for (int i = 0; i < M; ++i)
		ProcessProblumes();

	for (const auto& i : g_solution)
		std::cout << i << "\n";
}