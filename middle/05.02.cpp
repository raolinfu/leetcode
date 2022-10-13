#include <string>
using namespace std;

class Solution {
public:
    string printBin(double num) {
        if (num >= 1 || num <= 0)
            return "ERROR";

        string res = "0.";
        while (num)
        {
            if (res.length() >= 32)
                return "ERROR";
            num *= 2;
            if (num >= 1) {
                res += '1';
                num -= 1;
            } else {
                res += '0';
            }
        }
        
        return res;
    }
};