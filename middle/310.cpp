#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<set<int>> vex(n);
        vector<int> mark(n, 0);
        for(auto& x: edges){//建立邻接表和度数表
            int a = x[0], b = x[1];

            vex[a].insert(b);
            vex[b].insert(a);
            mark[a]++;
            mark[b]++;
        }

        queue<int> Q;
        for(int i = 0; i < n; i++){//初始化队列
            if(mark[i] <= 1){
                Q.push(i);
            }
        }

        while(Q.size() != n){//如果剩余的点在同一层，它们即为所求点集
            int size = Q.size();
            n -= size;//本轮遍历size个点，更新剩余点数量n

            while(size--){//遍历外层的点
                int p = Q.front();
                Q.pop();

                for(auto& x: vex[p]){//把相邻点的度数-1，把新的度为1的点入队（作为下一层）
                    if(mark[x] > 1){
                        mark[x]--;
                        if(mark[x] == 1){
                            Q.push(x);
                        }                        
                    }
                }
            }
        }

        vector<int> ans;
        while(Q.size()){//把所求的点集转移至数组
            ans.push_back(Q.front());
            Q.pop();
        }

        return ans;
    }
};
