class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                // i to i+2, j to j+2
                 if(grid[i+1][j+1] != 5) continue;
                vector<int> rowsum;
                vector<int> colsum;
                int sum=0;
                for(int k=i;k<=i+2;k++){
                    sum=0;
                    for(int l=j;l<=j+2;l++)
                    sum += grid[k][l];  
                    colsum.push_back(sum);
                }
                for(int k=j;k<=j+2;k++){
                    sum=0;
                    for(int l=i;l<=i+2;l++)
                    sum += grid[l][k];  
                    rowsum.push_back(sum);
                }
                vector<int> diagsum;
                sum=0;
                for(int l=0;l<=2;l++){
                    sum+=grid[i+l][j+l];
                }
                diagsum.push_back(sum);
                sum=grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                diagsum.push_back(sum);
                int checksum=rowsum[0];
                bool flag=true;
                for(auto x: rowsum){
                    if(checksum!=x) flag=false;
                }
                for(auto x: colsum){
                    if(checksum!=x) flag=false;
                }
                for(auto x: diagsum){
                    if(checksum!=x) flag=false;
                }
                vector<int> seen(9, 0);
for(int k=i;k<=i+2;k++){
    for(int l=j;l<=j+2;l++){
        int v = grid[k][l];
        if(v < 1 || v > 9 || seen[v-1]) flag = false;
        else seen[v-1] = 1;
    }
}
                if(flag) count++;
            }
        }
        return count;
    }
};