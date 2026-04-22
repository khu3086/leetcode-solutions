class Solution {
public:
    void dfs(int num, vector<vector<int>>& myboard, vector<vector<char>>& board, int i, int j, int m, int n){
        if(i<0||j<0||i>=m||j>=n||myboard[i][j]!=0|| board[i][j] != 'O') return;
        myboard[i][j]=num;
        dfs(num, myboard, board, i+1, j, m, n);
        dfs(num, myboard, board, i-1, j, m, n);
        dfs(num, myboard, board, i, j+1, m, n);
        dfs(num, myboard, board, i, j-1, m, n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> myboard(m, vector<int>(n, 0));
        vector<vector<int>> sources;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            sources.push_back({i, j});
        }
        for(int i=0;i<sources.size();i++){
            dfs(i+1, myboard, board, sources[i][0], sources[i][1], m, n);
        }
        //check filled edge elements, those O can be skipped
        set<int> skip;
        for(int i=0;i<m;i++){
            if(myboard[i][0]!=0) skip.insert(myboard[i][0]);
            if(myboard[i][n-1]!=0) skip.insert(myboard[i][n-1]);
        }
        for(int j=0;j<n;j++){
            if(myboard[0][j]!=0) skip.insert(myboard[0][j]);
            if(myboard[m-1][j]!=0) skip.insert(myboard[m-1][j]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&skip.find(myboard[i][j])==skip.end())
                board[i][j]='X';
            }
        }
    }
};