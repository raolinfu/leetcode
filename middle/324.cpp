#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
int len = nums.size();
        int bucket[5001] = {0};
        for (int num:nums) {
            bucket[num]++;
        }
        int big, small;
        if (len&1){
            big = len-2;
            small = len-1;
        }else{
            big = len-1;
            small = len-2;
        }
        int j = 5000;
        // insert big
        for (int i = 1; i <= big; i+=2) {
            while (bucket[j] == 0) j--;
            nums[i]=j;
            bucket[j]--;
        }
        // insert small
        for (int i = 0; i <= small; i+=2) {
            while (bucket[j]==0)j--;
            nums[i]=j;
            bucket[j]--;
        }
    };

};
