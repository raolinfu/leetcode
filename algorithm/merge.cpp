#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        void sort(vector<int>& nums) {
            int n = nums.size();
            tmp = vector<int>(n);
            mergeSort(nums, 0, n - 1);
        };

    private:
        vector<int> tmp;
        void merge(vector<int>& nums, int i1, int b1, int i2, int b2) {
            int l1 = i1;
            int l2 = i2;
            int k = i1;
            while (l1 <= b1 || l2 <= b2) {
                if (l1 <= b1 && l2 <= b2) {
                    if (nums[l1] < nums[l2]) {
                        tmp[k] = nums[l1];
                        l1++;
                    } else {
                        tmp[k] = nums[l2];
                        l2++;
                    }
                } else if (l1 <= b1) {
                    tmp[k] = nums[l1];
                    l1++;
                } else if (l2 <= b2) {
                    tmp[k] = nums[l2];
                    l2++;
                }

                k++;
            }

            for (int i = i1; i <= b2; i++)
                nums[i] = tmp[i];
        }

        void mergeSort(vector<int>& nums, int i, int j) {
            if (i >= j)
                return;
            int m = i + (j - i) / 2;
            mergeSort(nums, i, m);
            mergeSort(nums, m + 1, j);
            merge(nums, i, m, m + 1, j);
        }
};
int main() {
    vector<int> nums {12, 32, 12, 3, 325, 9};
    Solution sol;
    sol.sort(nums);
    for (auto n: nums)
        cout<< n<< "\t";
    cout<< endl;
    return 0;
}
