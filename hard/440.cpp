#include <vector>
using namespace std;

class Solution {
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while(cur <= n) {
            count += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        // p为一个指针，指向当前所在位置，当p==k时，也就是到了排位第k的数
        long p = 1;
        long prefix = 1;
        while(p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                /// 说明第k个数，在这个前缀范围里面
                prefix *= 10;
                p++; // 字典序往后移动1个
            } else if (p+count <= k) {
                /// 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
                prefix++;
                p += count;
            }
        }
        return static_cast<int>(prefix);
    }
};
