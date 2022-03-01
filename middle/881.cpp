#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
		int ans = 0;
		std::sort(people.begin(), people.end());
		int left  = 0;
		int right = people.size() - 1;
		while(left < right){
			if(people[left] + people[right] <= limit){
				ans++;
				left++;
				right--;
			}else{
				ans++;
				right--;
			}
		}
		if(left == right)
			ans++;

		return ans;
    }
};
