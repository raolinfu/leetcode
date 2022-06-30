#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](auto& a, auto& b) {
                if (a[0] < b[0]) return true;
                else if (a[0] == b[0]) return a[1] > b[1];
                return false;
                });
        vector<int>& cur = clips[0];
        if (cur[0] > 0)
            return -1;
        else if (cur[1] >= time)
            return 1;

        int ans = 1;
        int i = 1;

        while (i < clips.size()) {
            vector<int> tmp = clips[i];
            while (i < clips.size() && clips[i][0] <= cur[1]) {
                if (clips[i][1] >= tmp[1])
                    tmp = clips[i];
                i++;
            }

            if (tmp[0] <= cur[1]) {
                ans++;
                cur = tmp;
                if (cur[1] >= time)
                    return ans;
            } else {
                return -1;
            }
        }

        return -1;
    }
};
