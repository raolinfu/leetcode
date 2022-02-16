#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=nums.size()-1;i>=2;i--){
         int x3=nums[i];
        int j=i-1,k=0;
        while(k<j){
            if(nums[k]+nums[j]>x3){
             ans+=j-k;
             j--;
            }
            else k++;
        }
     }
     return ans;
    }
};
