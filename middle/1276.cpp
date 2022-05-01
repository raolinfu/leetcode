#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        int n = tomatoSlices / 4;
        for (int i = 0; i <= n; i++) {
            int a = i;
            int b = (tomatoSlices - 4 * i) / 2;
            int mod = (tomatoSlices - 4 * i) % 2;
            if (mod)
                continue;
            if (a + b == cheeseSlices) {
                ans.push_back(a);
                ans.push_back(b);
                return ans;
            }
        }

        return ans;
    }
};
