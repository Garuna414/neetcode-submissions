class Solution {
int m, n;
vector<int> row={1,-1,0,0}, col={0,0,1,-1};
public:
    bool isValid (int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int gf = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vec(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                    vec[i][j] = 0;
                } else if (grid[i][j] == 1) gf++;
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + row[k], ny = y + col[k];
                if (isValid(nx,ny) && grid[nx][ny]==1 && vec[nx][ny]==-1) {
                    gf--;
                    vec[nx][ny] = vec[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        if (gf > 0) return -1;
        int maxTime = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxTime = max(maxTime, vec[i][j]);
            }
        }
        return maxTime;
    }
};
