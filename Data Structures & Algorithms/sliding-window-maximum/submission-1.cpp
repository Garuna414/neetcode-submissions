class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        deque<int> dq;
        for (int i = 0; i < k; i++) {
            if (dq.empty()) dq.push_back(nums[i]);
            else {
                if (nums[i] > dq.back()) {
                    while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        vector<int> res;
        res.push_back(dq.front());
        for (int i = k; i < len; i++) {
            if (nums[i] > dq.back()) {
                while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            }
            dq.push_back(nums[i]);
            if (nums[i-k] == dq.front()) dq.pop_front();
            res.push_back(dq.front());
        }
        return res;
    }
};
