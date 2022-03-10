#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		 unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
			// 这一步是跳过前面有数字的 本质之选自身处于开头的
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;         
    }
};
int main(){
	Solution sol;
	vector<int> nums = {1,2,0,1};
	cout<< sol.longestConsecutive(nums)<< endl;
	return 0;
}
