#include<string>
#include<iostream>
#include<vector>
using namespace std;

void process(vector<string> &res, string str, int left, int right, int &n);
vector<string> generateParenthesis(int n) {
	vector<string> res;
	int left = 0;
	int right = 0;
	string str = "";
	process(res, str, left, right, n);

	return res;
}

void process(vector<string> &res, string str, int left, int right, int &n){
	if(left == right && left == n)
		res.push_back(str);
	if(left < n && left > right){
		process(res, str + '(', left + 1, right, n);
		process(res, str + ')', left, right + 1, n);
	}else if(left < n && left == right){
		process(res, str + '(', left + 1, right, n);
	}else if(left == n && right < n){
		process(res, str + ')', left, right + 1, n);
	}
}

int main(){
	vector<string> res = generateParenthesis(3);
	for(auto s: res){
		cout<< s<< endl;
	}
	return 0;
}
