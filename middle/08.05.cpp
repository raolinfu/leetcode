class Solution {
public:
    int multiply(int A, int B) {
        if (B == 1)
            return A;
        int res = multiply(A, B >> 1) << 1;
        if (B & 1)
            res += A;
        return res;
    }
};