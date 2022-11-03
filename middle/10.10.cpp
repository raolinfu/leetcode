#include <climits>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

class StreamRank {
private:
    int cnt;
    int d[50005];
    int lc[50005];
    int rc[50005];

    void update(int curr, int l, int r, int v) {
        d[curr]++;
        if (l != r) {
            int m = (l + r) >> 1;
            if (m >= v) {
                if (!lc[curr]) lc[curr] = ++cnt;
                update(lc[curr],l,m,v);
            }

            else {
                if (!rc[curr]) rc[curr] = ++cnt;
                update(rc[curr],m+1,r,v);
            }
        }
    }

    int query(int curr, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return d[curr];
        else if (r < ql || qr < l) return 0;
        else {
            int m = (l + r) >> 1;
            int res = 0;
            if (lc[curr]) res += query(lc[curr], l, m, ql, qr);
            if (rc[curr]) res += query(rc[curr], m+1, r, ql, qr);
            return res;
        }
    }



public:

    StreamRank() {
        cnt = 1;
        memset(d,0,sizeof(d));
        memset(lc,0,sizeof(lc));
        memset(rc,0,sizeof(rc));
    }

    void track(int x) {
        update(1,INT_MIN/2,INT_MAX/2,x);
    }

    int getRankOfNumber(int x) {
        return query(1,INT_MIN/2,INT_MAX/2,INT_MIN/2,x);
    }
};


/**

 * Your StreamRank object will be instantiated and called as such:

 * StreamRank* obj = new StreamRank();

 * obj->track(x);

 * int param_2 = obj->getRankOfNumber(x);

 */
