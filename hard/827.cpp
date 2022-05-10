#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class UF {
    private:
        vector<int> parents;
        vector<int> size;
        int findParent(int a) {
            while (a != parents[a]) {
                a = parents[a];
                parents[a] = parents[parents[a]];
            }
            return a;
        }

    public:
        UF(int n) {
            parents = vector<int>(n);
            size = vector<int>(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                size[i] = 1;
            }
        }

        bool isConnected(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            return pa == pb;
        }

        void unify(int a, int b) {
            int pa = findParent(a);
            int pb = findParent(b);
            if (pa == pb)
                return;
            if (size[pa] > size[pb]) {
                parents[pb] = pa;
                size[pa] += size[pb];
            }
            else {
                parents[pa] = pb;
                size[pb] += size[pa];
            }
        }

        int getSize(int a) {
            int p = findParent(a);
            return size[p];
        }
};

class Solution {
private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int getHash(int i, int j, int n) {
        return i * n + j;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int zeroCnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        UF uf(n * n);
        queue<pair<int, int>> que;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    zeroCnt++;
                if (visited[i][j] == false && grid[i][j] == 1) {
                    que.push({i, j});
                    visited[i][j] = true;
                    while (!que.empty()) {
                        auto f = que.front();
                        int hash1 = getHash(f.first, f.second, n);
                        que.pop();
                        for (auto& p: directions) {
                            int row = p.first + f.first;
                            int col = p.second + f.second;
                            if (row >= 0 && row < n && col >=0 && col < n && grid[row][col] == 1 && visited[row][col] == false) {
                                int hash2 = getHash(row, col, n);
                                if (!uf.isConnected(hash1, hash2)) {
                                    uf.unify(hash1, hash2);
                                }

                                que.push({row, col});
                                visited[row][col] = true;
                            }
                        }
                    }
                }
            }
        }
        if (zeroCnt == 0)
            return n * n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int res = 1;
                    vector<int> tmp;
                    for (auto& p: directions) {
                        int row = p.first + i;
                        int col = p.second + j;
                        if (row >= 0 && row < n && col >=0 && col < n && grid[row][col] == 1 && visited[i][j] == false) {
                            int hashnaum = getHash(row, col, n);
                            bool flag = false;
                            for (auto& n: tmp) {
                                if (uf.isConnected(n, hashnaum)) {
                                    flag = true;
                                } 
                            }
                            if (!flag) {
                                tmp.push_back(hashnaum);
                                res += uf.getSize(hashnaum);
                                // cout<< row<< "\t"<< col<< "\t"<< uf.getSize(hashnaum)<< endl;
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> grid;

    return 0;
}
