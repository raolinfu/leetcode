#include<vector>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

void process(vector<int>& ans, int &n, int &k, string &str);
vector<int> numsSameConsecDiff(int n, int k) {
	vector<int> ans;
	string str;
	for(int i = 1; i <= 9; i++){
		char ch = '0' + i;
		str.push_back(ch);
		process(ans, n, k, str);
		str.pop_back();
	}

	return ans;
}
void process(vector<int>& ans, int &n, int &k, string &str){
	if(str.length() == n){
		ans.push_back(stoi(str));
		return;
	}
	char back = str.back();
	if(back + k <= 9){
		str.push_back(back + k);
		process(ans, n, k, str);
		str.pop_back();
	}
	if(back - k >= 0){
		str.push_back(back - k);
		process(ans, n, k, str);
		str.pop_back();
	}
}

int main(){
	int n = 2;
	int k = 1;
	vector<int> ans = numsSameConsecDiff(n, k);
	for(auto ele: ans)
		cout <<ele << " ";
	cout<< endl;
	return 0;
}
