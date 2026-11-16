class Solution {
public:
    int maxArea(vector<int>& heights) {
        int len = heights.size();
        int l = 0, r = len - 1, maxVol = (r - l) * min(heights[l], heights[r]);
        while (l < r) {
            if (heights[l] <= heights[r]) l++;
            else r--;
            int currVol = (r - l) * min(heights[l], heights[r]);
            maxVol = max(maxVol, currVol);
        }
        return maxVol;
    }
};
