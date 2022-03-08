#include<vector>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
		stack<int> s;
        int n=nums.size();
        int len=0;
        if(n==0){return 0;}
        s.push(0);
		// 找到所有的坡底
        for(int i=1;i<n;i++){
            if(nums[s.top()]>nums[i]){
                s.push(i);
            }
        }
        for(int i=n-1;i>0;i--){
            while(!s.empty()&&nums[s.top()]<=nums[i]){
                len=max(len,i-s.top());
                s.pop();
            }
            if(s.empty()){return len;}
        }
        return len;
    }
};
