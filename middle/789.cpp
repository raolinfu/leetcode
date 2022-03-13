#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int d = abs(target[0]) + abs(target[1]);
		for(auto v: ghosts){
			int n = abs(v[0] - target[0]) + abs(v[1] - target[1]);
			if(n <= d)
				return false;
		}

		return true;
    }
};
