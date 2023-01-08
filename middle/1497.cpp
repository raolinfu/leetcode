#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for (auto& ele: arr) {
            int key = ((ele % k) + k) % k;
            ++mp[key];
        }

        for (auto& iter: mp) {
            int key = iter.first;
            int value = iter.second;
            int p = k - key;
            if (key == 0 && value % 2 == 0)
                continue;
            if (mp[p] != value)
                return false;
        }

        return true;
    }
};