#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = (nums.size() - 1) / 2;
        int i = 1;
        int j = n + 2;
        while (i <= n)
        {
            swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
    }
};