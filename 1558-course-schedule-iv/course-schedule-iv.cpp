class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        // floyd warshall
        vector<vector<bool>> reach(n, vector<bool>(n, false));
        for(auto x: pre){
            reach[x[0]][x[1]]=true;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(reach[i][k]&&reach[k][j]) reach[i][j]=true;
                }
            }
        }
        vector<bool> ans;
        for(auto x: queries){
            if(reach[x[0]][x[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};