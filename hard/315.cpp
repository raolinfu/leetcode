#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Bits {
    private:
        vector<int> nums;
        int n;

    public:
        Bits(int n): n(n), nums(vector<int>(n, 0)) {};

        int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += nums[i];
                i -= i & -i;
            }

            return sum;
        };

        void update(int i, int x) {
            // 注意这里的比较与传入构造函数是否+1是有关的
            while (i < n) {
                nums[i] += x;
                i += i & -i;
            }
        };
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ids(nums);
        sort(ids.begin(), ids.end());
        ids.erase(unique(ids.begin(), ids.end()), ids.end());
        for (int i = 0; i < ids.size(); i++)
            mp[ids[i]] = i;
        
        Bits bits(ids.size() + 1);
    
        for (int i = n - 1; i >= 0; i--) {
            int id = mp[nums[i]];
            int res = bits.query(id);
            bits.update(id + 1, 1);
            ans.push_back(res);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

};
