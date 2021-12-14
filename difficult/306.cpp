#include<string>
#include<iostream>
using namespace std;
/*
 *累加和
 * */
bool isValid(string &s){
	if(s.length() > 1 && s[0] == '0')
		return false;
	return true;
}
bool process(string &num, int first, int second, int idx);
bool isAdditiveNumber(string num) {
	for(int i = 1; i < num.length(); i++){
		string firstStr = num.substr(0, i);
		if(!isValid(firstStr))
			return false;
		int first = stoi(firstStr);
		for(int step = 1; step + i < num.length(); step++){
			string secondStr = num.substr(i, step);
			if(!isValid(secondStr))
				return false;
			int second = stoi(secondStr);	
			// cout<< "first: "<< first<< "  second: "<< second<< endl;
			if(process(num, first, second, i + step)){
				return true;
			}
		}
	}

	return false;
}

bool process(string &num, int first, int second, int idx){
	if(idx == num.length())
		return true;
	if(num[idx] == '0')
		return false;
	int tmp = first + second;
	/* cout<< "first: "<< first<< "  second: "<< second; 
	 * cout<< "  tmp: "<< tmp<< endl; */
	string tmpStr = to_string(first + second);
	if(num.length() - idx >= tmpStr.length() && isValid(num.substr(idx, tmpStr.size())) && num.substr(idx, tmpStr.size()) == tmpStr){
		return process(num, second, tmp, idx + tmpStr.length());
	}

	return false;
}

int main(){
	// string num = "199100199";
	string num = "112358";
	// string num = "212358";
	int res = isAdditiveNumber(num);
	cout<< res<< endl;
	cout<< stoi("679")<< endl;
	return 0;
}
