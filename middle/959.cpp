#include <vector>
#include <iostream>
using namespace std;

class Union {
    private:
        size_t cnt;
        vector<int> parents;
        vector<int> count;
        int find(int a);
    public:
        Union(size_t size);
        void unify(int a, int b);
        bool connected(int a, int b);
        int getCnt() { return cnt;};
};

Union::Union(size_t size) {
    cnt = size;
    parents = vector<int>(size);
    count = vector<int>(size);
    for (int i = 0; i < size; i++) {
        parents[i] = i;
        count[i] = 1;
	}
}

int Union::find(int a) {
    while (a != parents[a]) {
		parents[a] = parents[parents[a]];
        a = parents[a];
	}
    return a;
}

void Union::unify(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2)
        return;
    --cnt;
	if (count[p1] > count[p2]) {
		parents[p2] = p1;
		count[p1] += count[p2];
	} else {
		parents[p1] = p2;
		count[p2] += count[p1];
	} 
}

bool Union::connected(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);

    return p1 == p2;
}

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        Union u(cols * rows * 4);
        for (int i = 0; i < rows; i++) {
            int j = 0;
            while (j < grid[i].size()) {
                int a = (i * cols + j) * 4;
                int b = (i * cols + j) * 4 + 1;
                int c = (i * cols + j) * 4 + 2;
                int d = (i * cols + j) * 4 + 3;

                if (i > 0) {
                    u.unify(b, ((i - 1) * cols + j) * 4 + 3);
                }
                if (j > 0) {
                    u.unify(a, (i * cols + j - 1 ) * 4 + 2);
                }

                if (grid[i][j] == '\\') {
                    u.unify(b, c);
                    u.unify(a, d);
                } else if (grid[i][j] == '/') {
                    u.unify(a, b);
                    u.unify(c, d);
                } else {
                    u.unify(a, b);
                    u.unify(b, c);
                    u.unify(c, d);
                }
                j++;
            }
        }

        return u.getCnt();
    }
};