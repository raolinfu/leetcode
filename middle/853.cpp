#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = position.size();
		vector<double> costs;
		stack<double> stk;
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priq;
		for(int i = 0; i < n; i++)
			priq.push({position[i], speed[i]});
		while(!priq.empty()){
			auto top = priq.top();
			double time = (double(target - top.first)) / top.second;
			costs.push_back(time);
			priq.pop();
		}
		for(int i = 0; i < costs.size(); i++){
			while(!stk.empty() && stk.top() <= costs[i])
				stk.pop();
			stk.push(costs[i]);
		}

		return stk.size();
    }
};
int main(){
	Solution s;
	int target = 12;
	vector<int> position = {10,8,0,5,3};
	vector<int> speed = {2,4,1,1,3};
	cout<< s.carFleet(target, position, speed)<< endl;
	return 0;
}
