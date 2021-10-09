#include<vector>
#include<iostream>
using namespace std;
void process(vector<vector<int>> &res, vector<int> &nums, int &k, int sum, int b, int cnt);
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> nums;
	process(res, nums, k, n, 1, 0);
	return res;
}

void process(vector<vector<int>> &res, vector<int> &nums, int &k, int sum, int b, int cnt){
	if(sum == 0 && cnt == k){
		res.push_back(nums);
	}
	for(int i = b; i <= 9; i++){
		if(sum - i >=0){
			nums.push_back(i);
			process(res, nums, k, sum - i, i + 1, cnt + 1);
			nums.pop_back();
		}else{
			return;
		}
	}
}

int main(){
	int k = 3;
	int n = 7;
	vector<vector<int>> res = combinationSum3(k, n);
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout<< res[i][j] << " ";
		}
		cout<< endl;
	}
	return 0;
}
