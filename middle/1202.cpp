#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class UF {
    private:
        vector<int> size_;
        vector<int> parents_;
        int count_;
    public:
        UF(int cnt) {
            size_ = vector<int>(cnt);
            parents_ = vector<int>(cnt);

            for (int i = 0; i < cnt; i++) {
                parents_[i] = i;
                size_[i] = 1;
            }
            count_ = cnt;
        }

        int findParent(int n) {
            while (n != parents_[n]) {
                parents_[n] = parents_[parents_[n]];
                n = parents_[n];
            }

            return n;
        };

        void unify(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa == pb)
                return;
            if (size_[pa] > size_[pb]) {
                parents_[pb] = pa;
                size_[pa] += size_[pb];
            } else {
                parents_[pa] = pb;
                size_[pb] += size_[pa];
            }
            count_--;
        }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UF uf(s.length());
        unordered_map<int, pair<priority_queue<int>, priority_queue<char>>> mp;
        for (auto p: pairs) {
            uf.unify(p[0], p[1]);
        }

        for (int i = 0; i < s.length(); i++) {
            int parent = uf.findParent(i);
            if (!mp.count(parent)) {
                mp.insert({parent, {priority_queue<int>(), priority_queue<char>()}});
            }

            mp[parent].first.push(i);
            mp[parent].second.push(s[i]);
        }

        for (auto [k, v]: mp) {
            while (!v.first.empty()) {
                s[v.first.top()] = v.second.top();
                v.first.pop();
                v.second.pop();
            }
        }

        return s;
    }
};
int main() {
    Solution sol;
    /* string s = "dcab";
     * vector<vector<int>>pairs = {{0,3},{1,2}}; */
    /* string s = "dcab";
     * vector<vector<int>>pairs = {{0,3},{1,2}, {0, 2}}; */
    string s = "cba";
    vector<vector<int>>pairs = {{0,1},{1,2}};
    string res = sol.smallestStringWithSwaps(s, pairs);
    cout<< res<< endl;
    return 0;
}
