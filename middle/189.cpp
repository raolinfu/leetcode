#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void rotate(vector<int>& nums, int k) {
	int len = nums.size();
	k = k % len;
	std::reverse(nums.begin(), nums.begin() + len - k);
	std::reverse(nums.rbegin(), nums.rbegin() + k);
	std::reverse(nums.begin(), nums.end());
}

int main(){
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	rotate(nums, 3);

}
