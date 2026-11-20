class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size(), n0 = cost[0], n1 = cost[1];
        vector<int> minCost(len);
        minCost[0] = 0;
        minCost[1] = 0;
        if (len == 2) return min(n0, n1);
        else {
            for (int i = 2; i < len; i++) {
                int cost1 = minCost[i-1] + cost[i-1];
                int cost2 = minCost[i-2] + cost[i-2];
                minCost[i] = min(cost1, cost2);
            }
        }
        return min(minCost[len-2]+cost[len-2], minCost[len-1]+cost[len-1]);
    }
};
