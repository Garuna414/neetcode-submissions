class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, len = nums.size();
        vector<int> pleft(len,1), pright(len,1);
        for (int i = 0; i < len; i++) {
            prod *= nums[i];
            pleft[i] = prod;
        }
        prod = 1;
        for (int i = len-1; i >= 0; i--) {
            prod *= nums[i];
            pright[i] = prod;
        }
        vector<int> res(len,1);
        // for (int i : pleft) cout << i << ", ";
        // cout << endl;
        // for (int i : pright) cout << i << ", ";
        for (int i = 0; i < len; i++) {
            if (i == 0) res[i] = pright[i+1];
            else if (i == len-1) res[i] = pleft[i-1];
            else res[i] = pright[i+1] * pleft[i-1];
        }
        return res;
    }
};
