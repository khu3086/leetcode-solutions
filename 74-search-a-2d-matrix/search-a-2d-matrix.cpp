class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int low=0, high=m*n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int numMid=matrix[mid/n][mid%n];
            if(numMid==target) return true;
            else if(numMid>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};