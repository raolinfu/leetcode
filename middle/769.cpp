#include<vector>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
		int ans = 0;
		int minNum = arr[0];
		int maxNum = arr[0];
		int l = 0;
		int r = 0;
		while(r < arr.size()){
			if(minNum == l && maxNum == r){
				ans++;
				if(++r < arr.size()){
					minNum = arr[r];
					maxNum = arr[r];
					l = r;
				}
			}
			else{
                if(++r < arr.size())
                {
                    minNum = min(minNum, arr[r]);
                    maxNum = max(maxNum, arr[r]);
                }
			}
		}

		return ans;
    }
};
