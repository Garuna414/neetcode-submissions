class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (int i : nums) st.insert(i);
        int maxCount = 0, currCount = 0;
        for (int i : nums) {
            auto itr = st.find(i-1);
            if (itr == st.end()) {
                currCount++;
                int nxt = i+1;
                auto nxtitr = st.find(nxt);
                while (nxtitr != st.end()) {
                    currCount++;
                    nxt++;
                    nxtitr = st.find(nxt);
                }
                maxCount = max(maxCount, currCount);
                currCount = 0;
            }
        }
        return maxCount;
    }
};
