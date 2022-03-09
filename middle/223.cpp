#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		pair<int, int> point1{ax1, ay1};
		pair<int, int> point2{ax2, ay2};
		pair<int, int> point3{bx1, by1};
		pair<int, int> point4{bx2, by2};
		int arera1 = (ax2 - ax1) * (ay2 - ay1);
		int arera2 = (bx2 - bx1) * (by2 - by1);
		int ans = arera1 + arera2;

		if(ax1 < bx1){
			 point1 = {ax1, ay1};
			 point2 = {ax2, ay2};
			 point3 = {bx1, by1};
			 point4 = {bx2, by2};
		}else{
			 point3 = {ax1, ay1};
			 point4 = {ax2, ay2};
			 point1 = {bx1, by1};
			 point2 = {bx2, by2};
		}
		if(point3.first >= point2.first || point3.second >= point2.second || point4.second <= point1.second){
			return ans;
		}else if(point3.second > point1.second && point3.second < point2.second){
			ans -= (point2.first - point3.first) * (point2.second - point3.second);
		}else if(point4.second > point1.second && point4.second < point2.second){
			ans -= (point2.first - point3.first) * (point4.second - point1.second);
		}

		return ans;
    }
};
