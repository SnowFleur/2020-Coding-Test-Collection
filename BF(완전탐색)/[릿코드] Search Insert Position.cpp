#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int answer{ -1 };

        for (int i = 0; i < nums.size(); ++i) {
            if (target <= nums[i]) {
                answer = i;
                break;
            }
        }

        //Not Find Insert Position
        if (answer == -1) {
            answer = nums.size();
        }

        return answer;
    }
};

int main() {
    Solution s;

    vector<int>nums{1,3,5,6};
    int target = 7;

    std::cout << s.searchInsert(nums, target) << "\n";
}