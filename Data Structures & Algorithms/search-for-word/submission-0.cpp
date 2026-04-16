class Solution {
   public:
    int drx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool func(int index, int r, int c, string word, vector<vector<char>>& board,
              vector<vector<int>>& vis) {
        if (r < 0 || c < 0 || r == board.size() || c == board[0].size() || vis[r][c] ||
            board[r][c] != word[index])
            return false;
        if (index == word.size()-1) return true;
        vis[r][c] = 1;
        // cout << r << " " << c << "\n";
        for (int i = 0; i < 4; i++) {
            int nr = r + drx[i][0];
            int nc = c + drx[i][1];
            if(func(index + 1, nr, nc, word, board, vis)) return true;
        }
        vis[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(func(0, i, j, word, board, vis)) return true;
            }
        }
        return false;
    }
};
