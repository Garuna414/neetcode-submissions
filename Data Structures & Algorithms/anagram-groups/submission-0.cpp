class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            vec.push_back({t, s});
        }
        map<string, vector<string>> mp;
        int len = vec.size();
        for (int i = 0; i < len; i++) {
            mp[vec[i][0]].push_back(vec[i][1]);
        }
        vec = {};
        for (auto p : mp) {
            vec.push_back(p.second);
        }
        return vec;
    }
};
