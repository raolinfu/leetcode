#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int N = arr.size() , oneNum = 0;       
        for (const int& a : arr) 
            if (a) ++oneNum;
        
        if (oneNum % 3) return {-1,-1};
        if (!oneNum) return {0,N-1};
        int T = oneNum / 3;
        
        int k = -1;
        function<int()> f = [&] () {
            //find the next 1
            while (!arr[++k]) ;
            return k;
        };
        function<int(int)> g = [&] (int p) {
            while (--p > 0) 
                f();
            return k;
        };
        
        //[i1,j1] , [i2,j2] , [i3,j3]
        int i1 = f(), j1 = g(T), i2 = f(), j2 = g(T), i3 = f(), j3 = g(T);
        int diff = N - j3;
        if (i2 - j1 < diff || i3 - j2 < diff) {
            return {-1,-1};
        }
        while (i1 <= j1) {
            if (arr[i1++] != arr[i2] || arr[i2++] != arr[i3++]) 
                return {-1,-1};
        }
        
        return {j1 + diff - 1 , j2 + diff};
    }
};
