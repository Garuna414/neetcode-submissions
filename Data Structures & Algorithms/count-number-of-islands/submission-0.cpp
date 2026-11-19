class Solution {
int m, n;
vector<int> row = {1,-1,0,0}, col = {0,0,1,-1};
public:
    bool isValid (int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        stack<pair<int, int>> st;
        vector<vector<int>> vec(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vec[i][j] == 0) {
                    st.push(make_pair(i,j));
                    count++;
                    vec[i][j] == 1;
                    while (!st.empty()) {
                        int x = st.top().first, y = st.top().second;
                        st.pop();
                        for (int k = 0; k < 4; k++) {
                            int nx = x + row[k], ny = y + col[k];
                            if (isValid(nx, ny) && grid[nx][ny] == '1' && vec[nx][ny] == 0) {
                                st.push(make_pair(nx, ny));
                                vec[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
