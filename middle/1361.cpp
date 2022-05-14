#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class UF {
    private:
        vector<int> parents_;
        int cnt_;

        int findParent(int a) {
            while (a != parents_[a]) {
                a = parents_[a];
                parents_[a] = parents_[parents_[a]];
            }
            return a;
        }

        bool isConnected(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            return pa == pb;
        }

    public:
        UF(int n) {
            parents_ = vector<int>(n);
            cnt_ = n;
            for (int i = 0; i < n; i++) {
                parents_[i] = i;
            }
        }

        void unify(int a, int b) {
            if (isConnected(a, b))
                return;

            int pa = findParent(a);
            int pb = findParent(b);
            parents_[pb] = pa;
            cnt_--;
        }

        int getCnt() {
            return cnt_;
        };
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parents(n, -1);
        UF uf(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (rightChild[i] == leftChild[i]) { 
                    return false;
                }

                // 某个点已经有父节点了
                if (parents[leftChild[i]] != -1)
                    return false;
                else
                    parents[leftChild[i]] = i;

                // 互为父节点
                if (parents[i] == leftChild[i])
                    return false;

                uf.unify(i, leftChild[i]);
            }

            if (rightChild[i] != -1) {
                if (parents[rightChild[i]] != -1)
                    return false;
                else
                    parents[rightChild[i]] = i;

                if (parents[i] == rightChild[i])
                    return false;

                uf.unify(i, rightChild[i]);
            }
        }

        return uf.getCnt() == 1;
    }
};
