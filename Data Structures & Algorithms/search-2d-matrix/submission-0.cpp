class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), lr = 0, hr = m-1, mr = (lr + hr) / 2;
        while (lr <= hr) {
            mr = (lr + hr) / 2;
            if ((target >= matrix[mr][0]) && (target <= matrix[mr][n-1])) {
                int lc = 0, hc = n-1;
                while (lc <= hc) {
                    int mc = (lc + hc) / 2;
                    if (matrix[mr][mc] == target) return true;
                    else if (target < matrix[mr][mc]) hc = mc - 1;
                    else if (target > matrix[mr][mc]) lc = mc + 1;
                }
                return false;
            } 
            else if (target < matrix[mr][0]) hr = mr - 1;
            else if (target > matrix[mr][n-1]) lr = mr + 1;
        }
        return false;
    }
};
