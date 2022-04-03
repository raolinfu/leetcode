#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<string>> buckets(26, vector<string>());
        for (auto word: words) {
            buckets[word[0] - 'a'].emplace_back(word);
        }
        for (char ch: s) {
            vector<string> bucket = buckets[ch - 'a'];
            // 注意这里 旧桶去除首字母后仍可能是放在旧桶里
            buckets[ch - 'a'].clear();
            for (auto word: bucket) {
                if (word.length() == 1) {
                    ans++;
                    continue;
                }

                buckets[word[1] - 'a'].emplace_back(word.substr(1));
            }
        }
        return ans;
    }


    // 暴力解法 超时
    int numMatchingSubseq1(string s, vector<string>& words) {
        int ans = 0;
        for (auto str: words) {
            if (isValid(s, str))
                ans++;
        }

        return ans;
    }
    
    bool isValid(string& s, string& str) {
        int len1 = s.length();
        int len2 = str.length();
        if (len1 < len2)
            return false;
        int i = 0;
        int j = 0;
        while (i < len1 && j < len2) {
            if (s[i] == str[j]) {
                j++;
            }
            i++;
        }

        return j == len2;
    }
};
