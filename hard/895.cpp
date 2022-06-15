#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class FreqStack {
private:
    // 存放频率 对应的元素 上面的最新
    unordered_map<int, vector<int>> mp;
    // 存放元素的频率
    unordered_map<int, int> cntMp;

public:
    int maxn = INT_MIN;
    FreqStack() {}
    
    void push(int val) {
        int tol = ++cntMp[val];
        // val 其实在tol - 1对应的栈里也有
        mp[tol].push_back(val);
        maxn = max(maxn, tol);
    }
    
    int pop() {
        int ret = 0;
        // maxn所对应的栈已经空了
        if(mp[maxn].size() == 0) 
            maxn--;

        if(mp[maxn].size()){
            ret = mp[maxn].back();
            // ret 其实在maxn - 1对应的栈里也有
            mp[maxn].pop_back();
            cntMp[ret]--;
        }

        return ret;
    }
};

