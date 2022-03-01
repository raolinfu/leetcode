#include<vector>
#include<cmath>
#include<stack>
#include<iostream>
using namespace std;
class Solution{
	public:
		int sumSubarrayMins(vector<int>& arr){
			long ans = 0;
			long mode = pow(10, 9) + 7;
			vector<int> pre(arr.size());
			vector<int> next(arr.size());
			stack<int> stk;
			stack<int> stk1;
			for(int i = 0; i < arr.size(); i++){
				while(!stk.empty() && arr[i] < arr[stk.top()])
					stk.pop();
				pre[i] = stk.empty()? -1: stk.top();
				stk.push(i);
			}

			for(int i = arr.size() - 1; i >= 0; i--){
				while(!stk1.empty() && arr[i] < arr[stk1.top()])
					stk1.pop();
				next[i] = stk1.empty()? arr.size(): stk1.top();
				stk1.push(i);
			}

			for(int i = 0; i < arr.size(); i++){
				ans += arr[i] * (long)(i - pre[i]) * (long)(next[i] - i);
			}

			return ans % mode;
		}
};
int main(){
	Solution s;
	vector<int> arr = {3,1,2,4};
	cout<< s.sumSubarrayMins(arr)<< endl;

	return 0;
}
