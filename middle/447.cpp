#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
		int n = points.size();
		int ans = 0;
		vector<vector<int>> distance(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			unordered_map<int, int> mp;
			for(int j = 0; j < n; j++){
				if(i == j)
					continue;
				// 以i为基点，j点到i的距离
				int d = pow(points[j][0] - points[i][0], 2) + pow(points[j][1] - points[i][1], 2);
				mp[d]++;
			}
			for(auto [k, v]: mp){
				if(v >= 2){
					ans += v * (v - 1);
				}
			}
		}

		return ans;
    }
};
