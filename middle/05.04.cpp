#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        vector<int> res;
        string binary;
        int cnt = 0;
        while (num) {
            binary += '0' + (num % 2);
            num = num / 2;
        }
        while (binary.size() < 31) {
            binary += '0';
        }
        std::reverse(binary.begin(), binary.end());
        int n = binary.size();
        int i = n - 1;
        while (i >= 0)
        {
            if (binary[i] == '1')
                cnt++;
            if (i - 1 >= 0 && binary[i] == '1' && binary[i - 1] == '0') {
                string tmp = binary;
                swap(tmp[i], tmp[i - 1]);
                cnt--;
                for (int j = n - 1; j > i; j--) {
                    if (cnt > 0)
                        tmp[j] = '1';
                    else
                        tmp[j] = '0';
                    cnt--;
                }
                res.push_back(revertBinary(tmp));
                break;
            }
            i--;
        }
        if (res.empty())
            res.push_back(-1);

        i = n - 1;
        cnt = 0;
        while (i >= 0)
        {
            if (binary[i] == '1')
                cnt++;
            if (i + 1 < n && binary[i] == '1' && binary[i + 1] == '0') {
                string tmp = binary;
                swap(tmp[i], tmp[i + 1]);
                cnt--;
                for (int j = i + 2; j < n; j++) {
                    if (cnt > 0)
                        tmp[j] = '1';
                    else
                        tmp[j] = '0';
                    cnt--;
                }
                res.push_back(revertBinary(tmp));
                break;
            }
            i--;
        }
        
        if (res.size() == 1)
            res.push_back(-1);
        return res;
    }

        int revertBinary(string str) {
        int res = 0;
        for (char ch: str) {
            if (ch == '1') {
                res = res * 2 + 1;
            } else {
                res = res * 2;
            }
        }

        return res;
    }
};