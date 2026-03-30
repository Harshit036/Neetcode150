class Solution {
public:
    int drx[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int r, int c, vector<vector<char>> &board){
        board[r][c] = '?';
        for(int i = 0; i < 4; i++){
            int nr = r + drx[i][0];
            int nc = c + drx[i][1];
            if(nr < 0 || nc < 0 || nr == board.size() || nc == board[0].size() || board[nr][nc] != 'O') continue;
            dfs(nr, nc, board);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, board);
        }
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O') dfs(0, i, board);
            if(board[m-1][i] == 'O') dfs(m-1, i, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '?') board[i][j] = 'O';
            }
        }
    }
};
