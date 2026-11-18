class Solution {
public:
    int findMin(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int l = 0, r = len-1, minnum = INT_MAX, m;
        while (l <= r) {
            if (nums[l] < nums[r]) {
                minnum = min(minnum, nums[l]);
                break;
            } 
            int m = (l + r) / 2;
            minnum = min(minnum, nums[m]);
            if (nums[m] >= nums[l]) l = m + 1;
            else r = m - 1;
        }
        return minnum;
    }
};

/*

4,0

*/
