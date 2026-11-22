class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            // cout << "l: " << l << " r: " << r << endl;
            if (nums[m] == target) return m;
            else if (nums[l] <= nums[m]) {
                if (target >= nums[l] && target <= nums[m]) {
                    r = m-1;
                } 
                // else if (target < nums[l] || target > nums[m]) {
                else {
                    l = m+1;
                }
            } else if (nums[l] > nums[m]) {
                if (target > nums[m] && target <= nums[r]) {
                    l = m+1;
                } 
                // else if (target < nums[m] || ) {
                else {
                    r = m-1;
                }
            }
        }
        return -1;
    }
};
