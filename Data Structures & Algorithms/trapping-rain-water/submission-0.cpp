class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> left(len+2), right(len+2);
        int maxLeft = 0, maxRight = 0;
        for (int i = 0; i < len; i++) {
            maxLeft = max(maxLeft, height[i]);
            left[i+1] = maxLeft;
        }
        left[len+1] = left[len];
        for (int i = len - 1; i >= 0; i--) {
            maxRight = max(maxRight, height[i]);
            right[i+1] = maxRight;
        }
        right[0] = right[1];
        int totVol = 0;
        for (int i = 1; i <= len; i++) {
            int minHeight = min(left[i-1], right[i+1]);
            if (minHeight > height[i-1]) totVol += minHeight - height[i-1];
        }
        return totVol;
    }
};

/*

 _[0,2,0,3,1,0,1,3,2,1]_
[x,0,2,0,3,1,0,1,3,2,1,x]
[0,1,2,3,4,5,6,7,8,9,10,11]
*/
