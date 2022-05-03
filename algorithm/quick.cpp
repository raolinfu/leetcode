#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Sloution {
    private:
        int partition(vector<int>& nums, int a, int b) {
            std::swap(nums[a], nums[b]);
            int i = a;
            int j = b - 1;
            while (i < j) {
                while (i < j && nums[i] <= nums[b])
                    i++;
                while (i < j && nums[j] > nums[b])
                    j--;
                std::swap(nums[i], nums[j]);
            }

            std::swap(nums[b], nums[i]);
            return i;
        };

    public:
        void quickSort(vector<int>& nums, int i, int j) {
            if (i >= j)
                return;
            int m = partition(nums, i, j);
            quickSort(nums, i, m - 1);
            quickSort(nums, m + 1, j);
        }
};

int main() {
    vector<int> nums {1, 32, 223, 23, 12};
    Sloution sol;
    for (auto n: nums)
        cout<< n<< "\t";
    cout<< endl;
    sol.quickSort(nums, 0, nums.size() - 1);
    
    for (auto n: nums)
        cout<< n<< "\t";
    cout<< endl;
    return 0;
}
