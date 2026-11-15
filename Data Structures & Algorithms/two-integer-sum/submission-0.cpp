class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> res;

        for (int i = 0; i < len; i++) {
            auto itr = mp.find(target - nums[i]);
            if (itr != mp.end()) {
                vector<int> ind = itr->second;
                if (ind[0]==i && ind.size()>1) {
                    res={i, ind[1]};
                    break;
                } else {
                    res = {i, ind[0]};
                    break;
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
