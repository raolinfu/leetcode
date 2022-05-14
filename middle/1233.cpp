#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct Tire {
    bool isEnd = false;
    string str;
    unordered_map<string, Tire*> children;

    vector<string> insert(vector<string>& strs, string& s) {
        vector<string> ans;
        Tire* cur = this;
        bool hasP = false;
        int i = 0;
        while (i < strs.size() && cur->children.count(strs[i])) {
            cur = cur->children[strs[i]];
            i++;
            if (cur->isEnd)
                hasP = true;
        }

        while (i < strs.size()) {
            Tire* node = new Tire();
            cur->children[strs[i]] = node;
            cur = node;
            i++;
        }

        cur->isEnd = true;
        cur->str = s;

        if (hasP) {
            ans.push_back(s);
            return ans;
        }

        queue<Tire*> que;
        que.push(cur);

        while (!que.empty()) {
            auto parent = que.front();
            que.pop();
            for (auto& child: parent->children) {
                if (child.second->isEnd) {
                    ans.push_back(child.second->str);
                }
                que.push(child.second);
            }
        }

        return ans;
    }

};

class Solution {
    unordered_set<string> st;
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for (auto& str: folder) {
            st.insert(str);
        }
        vector<string> ans;
        Tire tire;
        for (auto& str: folder) {
            helper(str, tire);
        }

        return vector<string>(st.begin(), st.end());
    }

    void helper(string& str, Tire& tire) {
        vector<string> strs;
        string tmp;
        for(char& ch: str) {
            if (ch == '/' && !tmp.empty()) {
                strs.push_back(tmp);
                tmp.clear();
                tmp = ch;
            } else {
                tmp += ch;
            }
        }

        strs.push_back(tmp);
        vector<string> res = tire.insert(strs, str);
        for (auto& s: res) {
            st.erase(s);
        }
    }
};
