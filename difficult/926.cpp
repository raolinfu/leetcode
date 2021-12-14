#include<string>
#include<climits>
#include<vector>
#include<iostream>
using namespace std;

int minFlipsMonoIncr(string s) {
	vector<int> zeroNums(s.length(), INT_MAX);
	vector<int> oneNums(s.length(), INT_MAX);
	if(s[0] == '0'){
		zeroNums[0] = 0;
		oneNums[0] = 1;
	}else{
		zeroNums[0] = 1;
		oneNums[0] = 0;
	}
	for(int i = 1; i < s.length(); i++){
		if(s[i] == '0'){
			zeroNums[i] = zeroNums[i - 1];
			oneNums[i] = min(zeroNums[i - 1], oneNums[i - 1]) + 1;
		}else{
			zeroNums[i] = zeroNums[i - 1] + 1;
			oneNums[i] = min(zeroNums[i - 1], oneNums[i - 1]);
		}
	}

	return min(zeroNums.back(), oneNums.back());
}

int main(){
	// string s = "00011000";
	// string s = "010110";
	string s = "11011";
	// string s = "00110";
	int res = minFlipsMonoIncr(s);
	cout<< res<< endl;
	return 0;
}
