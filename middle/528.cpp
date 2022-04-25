#include <vector>
#include <random>
using namespace std;

class Solution {
private:
    int sum = 0;
    vector<int> w;
public:
    Solution(vector<int>& w) {
        this->w = w;
        for (auto& n: this->w)
            sum += n;
    }
    
    int pickIndex() {
        int res = 0;
        int i = 0;
        while (true) {
            int n = rand() % res;
            if (n < w[i])
                return i;
            res -= w[i];
            i++;
        }
    }
};
