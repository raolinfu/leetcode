#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        int n = words.size();
        sort(words.begin(), words.end(), 
                [](string& str1, string& str2){return str1.length() < str2.length();});
        for (auto str: words)
            cout<< str<< "\t";
        cout<< endl;
        unordered_map<string, vector<string>> mp;
        unordered_map<string, int> res;
        for (int i = 0; i < n; i++) {
            mp[words[i]] = vector<string>();
            for (int j = i + 1; j < n; j++) {
                if (isValid(words[i], words[j]))
                    mp[words[i]].push_back(words[j]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            string& w = words[i];
            res[w] = 1;
            for (auto str: mp[w]) {
                res[w] = max(res[w], res[str] + 1);
            }
            ans = max(ans, res[w]);
        }

        return ans;
    }

    bool isValid(string& str1, string& str2) {
        if (str1.length() != str2.length() - 1)
            return false;
        int i = 0;
        int j = 0;
        while (i < str1.length() && j < str2.length()) {
            if (str1[i] == str2[j]) {
                i++;
            }
            j++;
        }

        return i == str1.length();
    }
};
