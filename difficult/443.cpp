#include<vector>
#include<iostream>
#include<string>
using namespace std;
int compress(vector<char>& chars) {
	string str;
	int cnt = 1;
	int len = chars.size();
	char pre = chars[0];
	for(int i = 1; i < len; i++){
		if(chars[i] == pre){
			cnt++;
		}
		else{
			str.push_back(pre);
			if(cnt != 1){
				str += to_string(cnt);
			}
			pre = chars[i];
			cnt = 1;
		}
	}

	str.push_back(chars[len - 1]);
	if(cnt != 1){
		str += to_string(cnt);
	}
	cout<< str<< endl;

	return str.length();
}
int main(){
	// vector<char>chars = {'a','a','b','b','c','c','c'};
	// vector<char>chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	vector<char>chars = {'a','b','b','b','b','b','b','b','b','b','b','b','3'};
	int res = compress(chars);
	cout<< res<< endl;
	return 0;
}
