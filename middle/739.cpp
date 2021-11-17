#include<vector>
#include<iostream>
/* 
 * 单调减栈 可以相等 如果
 * */
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> res(temperatures.size(), 0);
	vector<int> stack;
	for(int i = 0; i < temperatures.size(); i++){
		if(stack.size() == 0 || (temperatures[i] <= temperatures[stack.back()])){
			stack.push_back(i);
			continue;
		}
		while(stack.size() > 0 && temperatures[i] > temperatures[stack.back()]){
			int top = stack.back();
			res[top] = i - top;	
			stack.pop_back();
		}
		stack.push_back(i);
	}

	return res;
}

int main(){
	// vector<int>temperatures = {73,74,75,71,69,72,76,73};
	vector<int>temperatures = {30,74,75,76};
	vector<int> res = dailyTemperatures(temperatures);
	for(int n: res){
		cout<< n<< "\t";
	}
	cout<< endl;
	return 0;
}
