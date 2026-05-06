class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();

        // Step 1: Apply gravity
        for(int i = 0; i < row; i++) {
            int empty = col - 1;
            for(int j = col - 1; j >= 0; j--) {
                if(boxGrid[i][j] == '*') {
                    empty = j - 1;
                }
                else if(boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: Rotate 90° clockwise
        vector<vector<char>> result(col, vector<char>(row));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                result[j][row - 1 - i] = boxGrid[i][j];
            }
        }

        return result;
    }
};