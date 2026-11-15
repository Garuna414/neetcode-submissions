class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i : nums) mp[i]++;
        vector<vector<int>> vec;
        for (auto p : mp) {
            vec.push_back({p.second, p.first});
        }
        sort(vec.begin(), vec.end(), [](vector<int>&a, vector<int>&b){
            return a > b;
        });
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(vec[i][1]);
        }
        return res;
    }
};
