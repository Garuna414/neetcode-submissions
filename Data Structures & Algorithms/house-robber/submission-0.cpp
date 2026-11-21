class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        else if (len == 2) return max(nums[0], nums[1]);
        else {
            vector<int> robs(len, 0);
            robs[0] = nums[0];
            robs[1] = nums[1];
            int maxRob = 0;
            for (int i = 2; i < len; i++) {
                maxRob = max(robs[i-2]+nums[i], robs[i-1]);
                robs[i] = maxRob;
            }
            return maxRob;
        }
        return 0;
    }
};
