class Solution {
int inf = 2147483647, m, n;
vector<int> row = {1,-1,0,0}, col = {0,0,1,-1};
public:
    bool isValid (int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push(make_pair(i,j));
            }
        }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + row[k], ny = y + col[k];
                if (isValid(nx,ny) && grid[nx][ny] == inf) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
};
