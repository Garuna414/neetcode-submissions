class Solution {
int m, n;
vector<int> row = {1,-1,0,0}, col = {0,0,1,-1};
public:
    bool isValid (int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }
public:
    bool isAt (int i, int j) {
        return i==m-1 || j==n-1;
    }
public:
    bool isPa (int i, int j) {
        return i==0 || j==0;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                queue<pair<int,int>> q;
                vector<vector<int>> vec(m, vector<int> (n, 0));
                q.push(make_pair(i,j));
                bool pcheck = false, acheck = false, found = false;
                while (!q.empty()) {
                    int x = q.front().first, y = q.front().second;
                    // cout << x << " " << y << endl;
                    if (!pcheck) pcheck = isAt(x,y);
                    if (!acheck) acheck = isPa(x,y);
                    found = pcheck && acheck;
                    if (found) break;
                    vec[x][y] = 1;
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + row[k], ny = y + col[k];
                        if (isValid(nx,ny) && heights[nx][ny] <= heights[x][y] && vec[nx][ny] == 0) {
                            if (!pcheck) pcheck = isAt(nx,ny);
                            if (!acheck) acheck = isPa(nx,ny);
                            found = pcheck && acheck;
                            if (found) break;
                            q.push(make_pair(nx,ny));
                            vec[nx][ny] = 1;
                        }
                    }
                    if (found) break;
                }
                if (found) res.push_back({i,j});
            }
        }
        return res;
    }
};
