#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    // split 函数作用："4,#,#" -> ["4","#","#”]
    vector<string> split(string& preorder) {
        stringstream ss(preorder);
        string temp;
        vector<string> v;
        while(getline(ss, temp, ','))
            v.push_back(temp);
        return v;
    }

    bool isValidSerialization(string preorder) {
        vector<string> ss = split(preorder);
        int n = ss.size();
        int in = 0, out = 0;
        for (int i = 0, m = 0; i < n; i++) {
            if(ss[i] != "#") out += 2;
            if(i != 0) in++;
            if(i != n-1 && out <= in) return false;
        }

        return in == out;
    }
};


