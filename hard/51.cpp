#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
 *N皇后
 * */

void process(vector<vector<string>> &res, vector<string> &cur, unordered_map<int, int> &mp, int &n, int i);
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> cur;
	unordered_map<int, int> mp;
	process(res, cur, mp, n, 0);

	return res;
}

bool isValid(int i1, int j1, int i2, int j2){
	if(j1 == j2 || (abs(i1 - i2) == abs(j1 - j2)))
		return false;
	return true;
}

void process(vector<vector<string>> &res, vector<string> &cur, unordered_map<int, int> &mp, int &n, int i){
	if(i == n)
	{
		res.push_back(cur);
		return;
	}

	string row(n, '.');
	for(int j = 0; j < n; j++){
		int i2 = i;
		int j2 = j;
		bool valid = true;
		// 第二行开始要判断有效性
		if(i > 0)
			for(int k = 0; k < i; k++){
				int i1 = k;
				int j1 = mp[i1];
				if(!isValid(i1, j1, i2, j2)){
					valid = false;
					break;
				}
			}

		if(valid){
			row[j] = 'Q';
			mp[i] = j;
			cur.push_back(row);
			process(res, cur, mp, n, i + 1);
			cur.pop_back();
			row[j] = '.';
		}
	}
}

int main(){
	vector<vector<string>> res = solveNQueens(5);
	cout<< res.size()<< endl;
	for(int i = 0; i < res.size(); i++){
		for(auto str: res[i]){
			cout<< str<< endl;
		}
		cout<<"-------------" <<endl;
	}

	return 0;
}
