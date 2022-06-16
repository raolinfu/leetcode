#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty())
            return ans;

        unordered_map<int, int> mp;
        std::priority_queue<int> prq;
        for (int i = 0; i < k; i++) {
            prq.push(nums[i]);
        }

        ans.push_back(prq.top());

        for (int i = 0; i + k < nums.size(); i++) {
            int j = i + k;
            prq.push(nums[j]);
            mp[nums[i]]++;
            while (!prq.empty() && mp.count(prq.top())) {
                int top = prq.top();
                mp[top]--;
                prq.pop();

                if(mp[top] == 0) {
                    mp.erase(top);
                }

                ans.push_back(prq.top());
            }
        }

        return ans;
    }
};

int main() {
    std::priority_queue<int> prq;
    prq.push(12);
    prq.push(1);
    cout<< prq.top()<< endl;

    return 0;
}
