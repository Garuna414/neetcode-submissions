class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int len = h.size(), maxInt = 0;
        if (len == 1) return h[0];
        for (int i = 0; i < len; i++) {
            maxInt = max(maxInt, h[i]);
            if (i == 0) h[i] = min(h[i], h[i+1]);
            else if (i == len-1) h[i] = min(h[i], h[i-1]);
            else h[i] = min(h[i], max(h[i-1], h[i+1]));
        }
        int curr = h[0], currSize = 0, maxArea = 0;
        for (int i = 0; i < len; i++) {
            if (h[i] == curr) {
                currSize++;
                maxArea = max(maxArea, currSize * curr);
            } else {
                curr = h[i];
                currSize = 1;
                maxArea = max(maxArea, curr * currSize);
            }
        }
        return max(maxArea, maxInt);
    }
};
