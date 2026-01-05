class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int numNeg=0;
        int leastNegNum=INT_MAX;
        long long sum=0;
        int row=matrix.size();
        int col=matrix[0].size();
        bool isZero=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0) isZero=true;
                if(matrix[i][j]<0){
                    numNeg++;
                }
                leastNegNum=min(abs(matrix[i][j]), leastNegNum);
                sum+=abs(matrix[i][j]);
            }
        }
        if(isZero) return sum;
        if(leastNegNum!=INT_MAX) leastNegNum*=2;
        if(numNeg%2) sum-=leastNegNum;
        return sum;
    }
};