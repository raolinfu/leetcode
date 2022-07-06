#include <vector>
using namespace std;

class BinTreeVec {
    vector<int> nums;
public:
    BinTreeVec(int n): nums(vector<int>(n, 0)) {};

    void update(int i, int val) {
        int len = nums.size();
        int org = sumRange(i) - sumRange(i - 1);
        int diff = val - org;

        while (i < len) {
            nums[i] += diff;
            i += i & -i;
        }
    }

    int sumRange(int i) {
        int sum = 0;
        while (i > 0) {
            sum += nums[i];
            i -= i & -i;
        }
        return sum;
    }

};

class NumArray {
    BinTreeVec* p;
public:
    NumArray(vector<int>& nums) {
        p = new BinTreeVec(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            p->update(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        p->update(index + 1, val);
    }
    
    int sumRange(int left, int right) {
        int r_val = p->sumRange(right + 1);
        int l_val = p->sumRange(left);

        return r_val - l_val;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
