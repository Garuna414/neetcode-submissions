class Solution {
public:
    int findMin(vector<int> &nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int l = 0, r = len-1, minnum = INT_MAX;
        if (nums[l] < nums[r]) return nums[l];
        else {
            int m = (l + r) / 2;
            while (l < r) {
                m = (l + r) / 2;
                cout << "l: " << l << " r: " << r << " m: " << m << " mval: " << nums[m] << endl;
                if (nums[l] < nums[m]) l = m + 1;
                else if (nums[l] >= nums[m]) r = m - 1;
                minnum = min(minnum, nums[m]);
            }
            
        }
        return minnum;
    }
};

/*

4,0

*/
