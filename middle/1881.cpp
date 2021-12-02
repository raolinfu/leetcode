#include<string>
#include<iostream>
using namespace std;

string maxValue(string n, int x) {
	string str;
	int len  = n.length();
	int i = n[0] == '-'? 1: 0;
	if(i == 0){
		while('0' + x <= n[i] && i < len){
			str.push_back(n[i]);
			i++;
		}
	}
	else{
		str.push_back('-');
		while('0' + x >= n[i] && i < len){
			str.push_back(n[i]);
			i++;
		}
	}
	str.push_back('0' + x);
	while(i < len){
		str.push_back(n[i]);
		i++;
	}
	return str;
}
int main(){
	/* string n = "99";
	 * int x = 9; */
	string n = "-132";
	int x = 3;
	string str = maxValue(n, x);
	cout<< str<< endl;
	return 0;
}
