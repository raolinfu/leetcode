#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

struct Cmp {
    bool operator()(const pii& a, const pii& b) {
        return a.first * b.second > a.second * b.first;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pii, vector<pii>, Cmp> priq; 
        int n = arr.size();
        vector<int> pointers(n, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                priq.push({arr[pointers[i]], arr[i]});
                ++pointers[i];
            }
            mp[arr[i]] = i;
        }
        pii ans;
        while (!priq.empty()) {
            auto top = priq.top();
            int first = top.first;
            int second = top.second;
            --k;
            priq.pop();
            if (k == 0) {
                ans = top;
                break;
            }
            int idx = mp[second];
            if (pointers[idx] < idx) {
                priq.push({arr[pointers[idx]], second});
                ++pointers[idx];
            }
        }

        return {ans.first, ans.second};
    }
};
