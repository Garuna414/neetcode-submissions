class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size(), i = 0, j = 1, maxPr = 0;
        if (len == 1) return 0;
        while (j < len) {
            if (prices[j] < prices[i]) i = j;
            else maxPr = max(maxPr, prices[j] - prices[i]);
            j++;
        }
        return maxPr;
    }
};
