#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
				// 注意这里 left++ 后right++了，left只加一次 所以窗口大小一直是递增的
                left++;
            }
            right++;
        }
        return right - left;
    }
};

