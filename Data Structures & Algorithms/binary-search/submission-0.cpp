class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), l = 0, r = len-1, m = (l + m) / 2;
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] == target) return m;
            else if (target > nums[m]) l = m + 1;
            else if (target < nums[m]) r = m - 1;
        }
        return -1;
    }
};
