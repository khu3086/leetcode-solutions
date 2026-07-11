class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='X') return;
        vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        board[i][j]='C';
        for(auto d: dir){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0&&x<m&&y>=0&&y<n&&board[x][y]=='O')
            dfs(board, x, y, m, n);
        }
    }
    void solve(vector<vector<char>>& board) {
        //c->edge o, mark
        int m=board.size();
        int n=board[0].size();
            for (int i = 0; i < n; i++) {
    dfs(board, 0, i, m, n);      // Top row
}

for (int i = 0; i < n; i++) {
    dfs(board, m - 1, i, m, n);  // Bottom row
}

for (int i = 0; i < m; i++) {
    dfs(board, i, 0, m, n);      // Left column
}

for (int i = 0; i < m; i++) {
    dfs(board, i, n - 1, m, n);  // Right column
}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='C') board[i][j]='O';
            }
        }
    }
};