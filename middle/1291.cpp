#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<int> sequentialDigits(int low, int high) {
	vector<int> ans;
	string lowStr = to_string(low);
	string highStr = to_string(high);
	int l = lowStr.length();
	int h = highStr.length();
	int i = l;
	while(i <= h){
		for(int k = 1; k <= 9; k++){
			string str;
			char ch = '0' + k;
			int j = 0;
			while(j < i && ch <= '9'){
				str.push_back(ch);
				ch++;
				j++;
			}
			int cand = stoi(str);
			if(cand >= low && cand <= high && str.length() == i){
				ans.push_back(cand);
			}
		}
		i++;
	}

	return ans;
}
int main(){
	/* int low = 100;
	 * int high = 300; */
	int low = 1000;
	int high = 13000;
	vector<int> ans = sequentialDigits(low, high);
	for(int ele: ans){
		cout<< ele<< " ";
	}

	cout<< endl;
	return 0;
}
