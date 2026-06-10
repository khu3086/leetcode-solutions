class NumMatrix {
public:
    vector<vector<int>> sumMat;

    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        sumMat.resize(row + 1, vector<int>(col + 1, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sumMat[i + 1][j + 1] =
                    sumMat[i + 1][j] +
                    sumMat[i][j + 1] -
                    sumMat[i][j] +
                    matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;

        return sumMat[row2][col2]
             - sumMat[row1][col2]
             - sumMat[row2][col1]
             + sumMat[row1][col1];
    }
};