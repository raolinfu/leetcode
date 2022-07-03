#include <queue>
#include <vector>

using namespace std;
using pii = pair<int, int>;

struct Cmp {
    bool operator()(const pii& a, const pii& b) {
    return a.first > b.first;
    }
};

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> pointers(m + 1, 1);
        int ans;

        std::priority_queue<pii, vector<pii>, Cmp> priq;
        for (int i = 1; i <= m; i++) {
            int num = i * pointers[i];
            priq.emplace(num, i);
            pointers[i]++;
        }

        while (!priq.empty()) {
            auto [number, i] = priq.top();
            priq.pop();
            k--;
            if (k == 0) {
                ans = number;
                break;
            }

            if (pointers[i] <= n) {
                int num = i * pointers[i];
                priq.emplace(num, i);
                pointers[i]++;
            }
        }

        return ans;
    }
};

class Solution1 {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int x = left + (right - left) / 2;
            int count = x / n * n;
            for (int i = x / n + 1; i <= m; ++i) {
                count += x / i;
            }
            if (count >= k) {
                right = x;
            } else {
                left = x + 1;
            }
        }
        return left;
    }
};

