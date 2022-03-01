#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
	public:
		bool carPooling(vector<vector<int>>& trips, int capacity){
			vector<int> diff(10001, 0);
			vector<int> res(10001, 0);
			for(int i = 0; i < trips.size(); i++){
				increase(diff, trips[i][0], trips[i][1], trips[i][2], 10001);
			}

			res[0] = diff[0];
			if(res[0] > capacity)
				return false;
			for(int i = 1; i < 10001; i++){
				res[i] = res[i - 1] + diff[i];
				if(res[i] > capacity) 
					return false;
			}
			return true;
		}

		void increase(vector<int>& diff, int value, int i, int j, int n){
			diff[i] += value;
			if(j < n)
				diff[j] -= value;
		}
}
