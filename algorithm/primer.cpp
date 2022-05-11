#include <vector>
#include <iostream>
using namespace std;

// 埃氏筛
class Solution {
	public:
		void printPrimer(int n) {
			vector<bool> nums(n + 1, false);
			nums[0] = true;
			nums[1] = true;

			for (int i = 2; i < n + 1; i++) {
				if (nums[i] == false) {
					for (int j = i; i * j < n + 1; j++) {
						nums[i * j] = true;
					}
				}
			}

			for (int i = 2; i < n + 1; i++) {
				if (!nums[i])
					cout<< i<< endl;
			}
		}
};

int main() {
	Solution sol;
	sol.printPrimer(20);

	return 0;
}
