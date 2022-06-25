#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    int getCnt(int res) {
        int ans = 1;
        for (int i = 1; i <= res; i++)
            ans *= i;
        return ans;
    }
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> visited(n + 1, 0);
        int tol = 0;
        char ch = '1';
        int res = n - 1;

        while (tol < k) {
            int cnt = getCnt(res);
            if (tol + cnt >= k) {
                visited[ch - '0'] = 1;
                ans += ch;
                --res;
                if (tol + 1 == k) {
                    for (int i = 1; i <= n; i++)
                        if (visited[i] != 1){
                            ans += i + '0';
                        }
                    return ans;
                }

                for (int i = 1; i <= n; i++) {
                    if (visited[i] == 0 ) {
                        ch = i + '0';
                        break;
                    }
                }
            } else if (tol + cnt < k) {
                for (int i = ch - '0' + 1; i <= n; i++) {
                    if (visited[i] == 0 ) {
                        ch = i + '0';
                        cout<< ch<< endl;
                        break;
                    }
                }
                tol += cnt;
            }
        }

        return ans;
    }

};

int main() {
    Solution sol;
    cout<< sol.getPermutation(3, 2)<< endl;
    cout<< sol.getPermutation(4, 9)<< endl;
    cout<< sol.getPermutation(7, 19)<< endl;
    return 0;
}
