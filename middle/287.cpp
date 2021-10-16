#include<vector>
#include<iostream>
using namespace std;
/*
 *寻找重复数
 * */
int findDuplicate(vector<int>& nums)
{
	int res = 0;
	int maxBits = 0;
	int cur = 1;
	while (cur <= nums.size() - 1)
	{
		maxBits++;
		cur = cur << 1;
	}
	cur = 1;
	for (int j = 0; j < maxBits; j++)
	{
		int x = 0;
		int y = 0;
		cur = 1 << j;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] & cur)
				x++;
			if (i & cur)
				y++;
		}
		if (x > y)
		{
			res |= cur;
		}

	}

	return res;
}

int main()
{
	//vector<int> nums = {1, 2, 4, 3, 6, 7, 5, 6};
	vector<int> nums = {1, 2, 2};
	int res = findDuplicate(nums);
	cout << res << endl;
	return 0;
}
