#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
		int ans = 0;
		sort(points.begin(), points.end());
		int a1 = points[0][0];
		int b1 = points[0][1];
		int a2;
		int b2;
		for(int i = 1; i < points.size(); i++){
			a2 = points[i][0];
			b2 = points[i][1];
			if(!isInterect(a1, b1, a2, b2)){
				a1 = a2;
				b1 = b2;
				ans++;
			}else{
				a1 = a2;
				b1 = min(b1, b2);
			}
		}
		ans++;

		return ans;
    }
	bool isInterect(int& a1, int& b1, int& a2, int& b2){
		if(b1 < a2 || a2 > b1)
			return false;
		return true;
	}
};
