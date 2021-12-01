#include<string>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool isValid(string &str, unordered_set<char> set);
void process(vector<string>& arr, int &ans, unordered_set<char> set, int i);
int maxLength(vector<string>& arr) {
	int ans = 0;
	vector<string> strs;
	for(int i = 0; i < arr.size(); i++){
		unordered_set<char> set;
		if(isValid(arr[i], set))
			strs.push_back(arr[i]);
	}
	unordered_set<char> set;
	process(arr, ans, set, 0);

	return ans;
}

void process(vector<string>& arr, int &ans, unordered_set<char> set, int i){
	if(i == arr.size()){
		ans = max(ans, (int)set.size());	
		return;
	}

	process(arr, ans, set, i + 1);
	if(isValid(arr[i], set)){
		for(char ch: arr[i]){
			set.insert(ch);
		}
		process(arr, ans, set, i + 1);
	}
}

bool isValid(string &str, unordered_set<char> set){
	for(char ch: str){
		if(set.count(ch)){
			return false;
		}
		set.insert(ch);
	}
	return true;
}

int main(){
	// vector<string> arr = {"un","iq","ue"};
	vector<string>arr = {"cha","r","act","ers"};
	int ans = maxLength(arr);
	cout<< ans<< endl;
	return 0;
}
