#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> ans;
		for(int i = 1; i <= 9; i++){
			if(i > n)
				break;
			ans.push_back(i);
			helper(ans, n, i);
		}

		return ans;
    }

	void helper(vector<int>& ans, int& n, int num){
		for(int i = 0; i <= 9; i++){
			int tmp = num * 10 + i;
			if(tmp > n)
				break;
			ans.push_back(tmp);
			helper(ans, n, tmp);
		}
	}
};
int main(){
	Solution sol;
	auto nums = sol.lexicalOrder(13);
	for(auto n: nums)
		cout<< n<< "\t";
	cout<< endl;
	return 0;
}
