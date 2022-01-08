#include<vector>
#include<iostream>
using namespace std;

vector<double> sampleStats(vector<int>& count) {
	vector<double> ans(5);
	vector<int> freq(256, 0);
	int maxNum = 0;	
	int minNum = 255;
	int sum = 0;
	int midCnt = 0;
	int most = count[0];
	int midFirst = count[0];
	int midSecond = count[0];
	for(int num: count){
		minNum = min(minNum, num);
		maxNum = min(maxNum, num);
		sum += num;
		freq[num]++;
	}
	for(int i = 0; i < freq.size(); i++){
		if(freq[i] > freq[most]){
			most = i;
		}
	}
	// 求中位数
	for(int i = 0; i < freq.size(); i++){
		if(freq[i] > freq[most]){
			most = i;
		}
	}

	return ans;
}
