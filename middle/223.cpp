#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		vector<pair<int, int>> xNums{{ax1, 1}, {ax2, 1}, {bx1, 2}, {bx2, 2}};
		vector<pair<int, int>> yNums{{ay1, 1}, {ay2, 1}, {by1, 2}, {by2, 2}};
		sort(xNums.begin(), xNums.end());
		sort(yNums.begin(), yNums.end());
		int arera1 = (ax2 - ax1) * (ay2 - ay1);
		int arera2 = (bx2 - bx1) * (by2 - by1);
		int ans = arera1 + arera2;
		if(xNums[0].second == xNums[1].second || yNums[0].second == yNums[1].second)
			return ans;
		else{
			ans -= (xNums[2].first - xNums[1].first) * (yNums[2].first - yNums[1].first);
			return ans;
		}
    }
};
