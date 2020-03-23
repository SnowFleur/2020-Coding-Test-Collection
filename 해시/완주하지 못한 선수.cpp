#include <string>
#include <vector>
#include<set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	multiset<string> set_partic;
	multiset<string> set_compl;

	string answer = "";
	for (auto& iter : participant) {
		set_partic.insert(iter);
	}
	for (auto& iter : completion) {
		set_compl.insert(iter);
	}

	for (auto& iter : set_partic) {

		if (set_compl.count(iter)) {

			auto par_result = set_partic.count(iter);
			auto compl_result = set_compl.count(iter);

			if (par_result - compl_result != 0) {
				return iter;
			}

		}
		else
			return iter;
	}
}