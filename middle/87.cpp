#include<string>
#include<iostream>
#include<vector>
using namespace std;
/*
 *扰乱字符串
 * */
bool process(string x, string y, string s2);
bool isScramble(string s1, string s2) {
	for(int i = 0; i < s1.size(); i++){
		if(process(s1.substr(i, s1.size() -i), s1.substr(0, i), s2)){
			return true;
		}
	}
	return false;
}

bool process(string x, string y, string s2){
	if(x + y == s2)
		return true;
	if(x == s2.substr(0, x.size()))
	{
		for(int i = 0; i < y.size(); i++){
			if(process(y.substr(i, y.size() - i), y.substr(0, i), s2.substr(x.size(), s2.size() - x.size()))){
				return true;
			}
			return false;
		}	
	}

	return false;
}

int main(){
	string s1 = "great";
	string s2 = "rgeat";
	bool res = isScramble(s1, s2);
	cout<< res<< endl;
	return 0;
}
