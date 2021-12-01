#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
	int ans = 1;
	sort(intervals.begin(), intervals.end());
	int preFirst = intervals[0][0];
	int preSecond = intervals[0][1];
	for(int i = 1; i < intervals.size(); i++){
		int first = intervals[i][0];
		int second = intervals[i][1];
		if(first >= preFirst && second <= preSecond){
			continue;
		}
		else if(first != preFirst){
			ans++;
		}
		preFirst = first;
		preSecond = second;
	}

	return ans;
}
int main(){
	vector<vector<int>>intervals = {{1,4},{3,6},{2,8}};
	int ans = removeCoveredIntervals(intervals);
	cout << ans<< endl;
	return 0;
}
