class Solution {
int m, n;
vector<int> row = {1,-1,0,0}, col = {0,0,1,-1};
public:
    bool isValid (int i, int j) {
        return i>=0 && i<m && j>=0 && j<n;
    }

public:
    void markx (int i, int j, vector<vector<int>>& vec, vector<vector<char>>& board) {
        stack<pair<int,int>> st;
        if (board[i][j] == 'O') {
            st.push(make_pair(i,j));
            vec[i][j] = 0;
        }
        while (!st.empty()) {
            int x = st.top().first, y = st.top().second;
            st.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + row[k], ny = y + col[k];
                if (isValid(nx,ny) && board[nx][ny]=='O' && vec[nx][ny] == -1) {
                    vec[nx][ny] = 0;
                    st.push(make_pair(nx,ny));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<int>> vec(m, vector<int> (n, -1));
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') markx(i,0,vec,board);
            if (board[i][n-1] == 'O') markx(i,n-1,vec,board);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') markx(0,j,vec,board);
            if (board[m-1][j] == 'O') markx(m-1,j,vec,board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vec[i][j] == -1) board[i][j] = 'X';
            }
        }
    }
};
