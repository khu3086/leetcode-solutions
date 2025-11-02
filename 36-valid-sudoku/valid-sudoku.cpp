class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9];
        unordered_set<int> cols[9];
        unordered_set<int> boxes[9];
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c=board[i][j];
                if(c=='.') continue;
                int ctoi=c-'0';
                int boxi=(i/3)*3+j/3;
                if(rows[i].find(ctoi)!=rows[i].end()) return false;
                if(cols[j].find(ctoi)!=cols[j].end()) return false;
                if(boxes[boxi].find(ctoi)!=boxes[boxi].end()) return false;
                rows[i].insert(ctoi);
                cols[j].insert(ctoi);
                boxes[boxi].insert(ctoi);
            }
        }
        return true;
    }
};