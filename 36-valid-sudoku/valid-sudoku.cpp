class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                int val=board[i][j]-'0';
                if(rows[i].find(board[i][j])!=rows[i].end()) return false;
                if(cols[j].find(board[i][j])!=cols[j].end()) return false;
                int numBox=((i/3)*3)+j/3;
                if(boxes[numBox].find(board[i][j])!=boxes[numBox].end()) return false;
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[numBox].insert(board[i][j]);
            }
        }
        return true;
    }
};