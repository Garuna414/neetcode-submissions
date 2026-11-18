class Solution {
public:
    int calcTime (vector<int>& piles, int h, int k) {
        int totTime = 0;
        for (int i : piles) totTime += ceil(i / (k * 1.0));
        return totTime;
    }   
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int len = piles.size(), maxPile = 0;
        for (int i : piles) maxPile = max(maxPile, i);
        int l = 1, r = maxPile, minK = maxPile;
        while (l <= r) {
            int m = (l + r) / 2;
            int totTime = calcTime(piles, h, m);
            if (totTime > h) l = m + 1;
            else {
                r = m - 1;
                minK = min(minK, m);
            }
        }
        return minK;
    }
};
