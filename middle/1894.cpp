#include<vector>
#include<iostream>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k) {
	int sum = 0;
	vector<int> nums(chalk.size(), 0);
	for(int i = 0; i < chalk.size(); i++){
		sum += chalk[i];
		nums[i] = sum;
	}
	int cur = k % sum;
	for(int i = 0; i < nums.size(); i++){
		if(cur == 0){
			return i % nums.size();
		}
		else if(cur == cur % nums[i]){
			return i;
		}
	}
	
	return nums.size() + 1;
}

int main(){
	vector<int>chalk = {5,1,5};
	int k = 22;
	/* vector<int>chalk = {3,4,1,2};
	 * int k = 25; */
	int res = chalkReplacer(chalk, k);
	cout<< res<< endl;
	return 0;
}
