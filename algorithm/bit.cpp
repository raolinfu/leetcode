#include <vector>
#include <iostream>
using namespace std;
class Bit {
	private:
		int size;
		vector<int> nums;
	public:
		Bit(int n) {
			size = n;
			nums = vector<int>(n + 1, 0);
		}

		void Add(int i, int x) {
			while (i <= size) {
				nums[i] += x;
				// cout<< "i:"<< i<< "  nums[i]"<< nums[i]<<endl;
				i += i & -i;
			}
		}

		int Sum(int i) {
			int ans = 0;
			while (i > 0) {
				ans += nums[i];
				// cout<< "i:"<< i<< "  nums[i]"<< nums[i]<<endl;
				i -= i & -i;
			}

			return ans;
		}
};
int main() {
	Bit bit(8);
	cout<< bit.Sum(8)<< endl;
	bit.Add(1, 3);
	cout<< bit.Sum(8)<< endl;

	bit.Add(2, 3);
	cout<< bit.Sum(8)<< endl;
	cout<< bit.Sum(3)<< endl;

	return 0;
}
