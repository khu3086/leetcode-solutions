class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        sumMat.resize(row+1);
        for(int i=0;i<=row;i++) sumMat[i].resize(col+1);
        for(int i=0;i<=col;i++) sumMat[0][i]=0;
        for(int i=0;i<=row;i++) sumMat[i][0]=0;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                sumMat[i][j]=sumMat[i-1][j]+sumMat[i][j-1]-sumMat[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMat[row2+1][col2+1] 
             - sumMat[row1][col2+1] 
             - sumMat[row2+1][col1] 
             + sumMat[row1][col1];
    }
};

/**
 * Your NumMatrix objeceibccdcgelujrceriggcchdgtvivljlcvhgtlndtenih
 eibccdcgelujhevktdjrghbvrgcnerdhkcdivfjdvegg
 t will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */