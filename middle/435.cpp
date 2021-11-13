#include<vector>
#include<utility>
#include<algorithm>
#include<iostream>

using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int len = intervals.size();
	vector<int> dp(len, 1);	
	vector<pair<int, int>> pairs(len);
	for(int i = 0; i < len; i++){
		pairs[i] = make_pair(intervals[i][0], intervals[i][1]);
	}
	sort(pairs.begin(), pairs.end(), [](const pair<int, int> a,const pair<int, int> b )->bool{
				if(a.first < b.first)
					return true;
				else if(a.first == b.first)
					return a.second < b.second;
				return false;
			});
	for(int i = 1; i < len; i++){
		dp[i] = dp[i - 1];
		for(int j = i - 1; j >= 0; j--)
		{
			if(pairs[j].second <= pairs[i].first){
				dp[i] = max(dp[i], dp[j] + 1);
				break;
			}
		}
	}
	/* for(int i = 0; i < len; i++){
	 *     cout<< dp[i]<< endl;
	 * } */

	return len - dp[len - 1];
}

int main(){
	// vector<vector<int>> intervals = { {1,2}, {2,3}, {3,4}, {1,3} };
	vector<vector<int>> intervals { {1,2}, {1,2}, {1,2} };
	int res = eraseOverlapIntervals(intervals);
	cout<< res<< endl;
	return 0;
}
