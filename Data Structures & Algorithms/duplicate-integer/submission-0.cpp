class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for (int i : nums) {
            auto itr = st.find(i);
            if (itr != st.end()) return true;
            else st.insert(i);
        }
        return false;
    }
};