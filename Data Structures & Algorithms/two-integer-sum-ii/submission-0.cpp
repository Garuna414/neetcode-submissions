class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int f = target - nums[i], l = i+1, r = len - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (nums[m] == f) return {i+1, m+1};
                else if (f > nums[m]) l = m + 1;
                else if (f < nums[m]) r = m - 1;
            }
        }
        return {};
    }
};
