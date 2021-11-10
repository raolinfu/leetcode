#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	vector<int> nums = {1, 32, 3, 53, 26};
	sort(nums.begin(), nums.end(), [](const int &a, const int &b){return a > b;});
	for(int n: nums)
		cout<< n<< endl;

	return 0;
}
