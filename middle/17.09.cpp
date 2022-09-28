#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<long, vector<long>, greater<long>> pri_que;
        unordered_set<long> st;
        long nums[3] = {3, 5, 7};
        int cnt = 0;
        long ans = 1;

        pri_que.push(1);
        st.insert(1);

        while (cnt < k) {
            ans = pri_que.top();
            pri_que.pop();

            for (int i = 0; i < 3; i++) {
                long n = ans * nums[i];
                if (!st.count(n)) {
                    pri_que.push(n);
                    st.insert(n);
                }
            }

            ++cnt;
        }

        return ans;
    }
};