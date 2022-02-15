#include<string>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
		int ans = INT_MAX;
		sort(timePoints.begin(), timePoints.end());
		ans = min(ans, 1440 - getInterval(*timePoints.begin(), *timePoints.rbegin()));
		for(int i = 0; i < timePoints.size() - 1; i++){
			ans = min(ans, getInterval(timePoints[i], timePoints[i + 1]));
		}
		return ans;
    }

	int getInterval(string& t1, string& t2){
		int idx = 0;
		while(t1[idx] != ':'){
			idx++;
		}
		int a1 = stoi(t1.substr(0, idx));
		int b1 = stoi(t1.substr(idx + 1, t1.length()));

		idx = 0;
		while(t2[idx] != ':'){
			idx++;
		}
		int a2 = stoi(t2.substr(0, idx));
		int b2 = stoi(t2.substr(idx + 1, t2.length()));
		return b2 - b1 + (a2 - a1) * 60;
	}
};
int main(){
	Solution s;
	// vector<string> timePoints = {"23:59","00:00"};
	vector<string>timePoints = {"00:00","23:59","00:00"};
	int ans = s.findMinDifference(timePoints);
	cout<< ans<< endl;
	return 0;
}
