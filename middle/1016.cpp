#include<string>
#include<bitset>
using namespace std;
const int MAX_BITSISE_OF_NUM = 20;

class Solution {
public:
    bool queryString(string S, int N) {
        for (int i = 1; i <= N; i++) {
            bitset<MAX_BITSISE_OF_NUM> bitvec(i);
            string temp = bitvec.to_string();
            temp.erase(0, temp.find_first_of('1'));
            if (S.find(temp) == S.npos)
				return false;
        }
        return true;
    }
};
