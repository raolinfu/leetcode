#include <vector>
using namespace std;
class UF {
    private:
        int size_;
        vector<int> parents_;

        int findParent(int a) {
            while (a != parents_[a])
                a = parents_[a];
            return a;
        }
    public:
        UF(int size): size_(size) {
            parents_ = vector<int>(size_);
            for (int i = 0; i < size_; i++)
                parents_[i] = i;
        };

        bool connected(int a, int b) {
            return findParent(a) == findParent(b);
        };

        void unify(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            parents_[pb] = pa;
        }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        UF uf(n);
        for (auto v: edges) {
            if (uf.connected(v[0] - 1, v[1] - 1)) {
                ans = v;
                break;
            }
            uf.unify(v[0] - 1, v[1] - 1);
        }

        return ans;
    }
};
