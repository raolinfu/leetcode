#include <vector>
#include <iostream>
using namespace std;
using pii = pair<int, int>;

class MyCalendar {
    vector<pii> nums;

public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        int n = nums.size();
        if (n == 0) {
            nums.push_back({start, end});
            return true;
        }

        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m].second <= start) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (r == -1) {
            if (nums[0].first < end)
                return false;
            nums.insert(nums.begin(), {start, end});
            return true;
        } else if ((l < n && nums[l].first >= end) || l == n) {
            nums.insert(nums.begin() + l, {start, end});
            return true;
        }


        return false;
    }
};

int main() {
    vector<int> nums = {2};
    nums.insert(nums.begin(), 3);
    for (auto n: nums)
        cout<< n<< endl;

    return 0;
}
