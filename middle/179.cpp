#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string largestNumber(vector<int>& nums) {
	string res;
	sort(nums.begin(), nums.end(), [](const int& a, const int& b){
				return to_string(a) + to_string(b) > to_string(b) + to_string(a);
			});
	if(*nums.rbegin() == 0 && *nums.rbegin() == *nums.begin())
		return to_string(0);

	for(int num: nums){
		res += to_string(num);
	}
	
	return res;
}

int main(){
	//vector<int> nums = {12, 4, 6, 32, 3};
	vector<int> nums = {0, 0, 0};
	string res = largestNumber(nums);

	cout<< res<< endl;
}

