#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>
#include<iostream>
using namespace std;
/* 
 * 二叉树寻路 本质是个数学公式问题
 * pow(2, level - 1) + pow(2. level) - n - 1
 * */
vector<int> pathInZigZagTree(int label) {
	vector<int> res;
	deque<int> dq;
	int level = 1;
	while(label >= (1 << level)){
		level++;
	}
	int n = label;
	while(n > 1){
		dq.push_back(n);
		n = n /2;
	}
	dq.push_back(1);
	bool flag = true;
	while(dq.size()){
		int ele = dq.front();
		if(flag){
			res.push_back(ele);
		}else{
			int tmp = pow(2, level - 1) + pow(2, level) - ele - 1;
			res.push_back(tmp);
		}
		dq.pop_front();
		level--;
		flag = !flag;
	}

	reverse(res.begin(), res.end());
	return res;
}

int main(){
	// int n = 14;
	int n = 26;
	vector<int> res = pathInZigZagTree(n);
	for(auto n: res){
		cout<< n<< "\t";
	}
	cout<< endl;
	return 0;
}
