class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for (auto& n: nums) {
            if (n % 2 == 0)
                sum += n;
        }
        //cout<< "begin:"<< sum<< endl;
        for (auto& q: queries) {
            int& val = q[0];
            int& idx = q[1];
            if (val % 2) { // odd
                if (nums[idx] % 2) {
                    sum += (val + nums[idx]);
                } else {
                    sum -= nums[idx];
                }
            } else {    // even
                if (nums[idx] % 2 == 0) {
                    sum += val;
                }    
            }
            //cout<< sum<< endl;
            ans.push_back(sum);
            
            nums[idx] += val;
        }
        
        return ans;
    }
};
