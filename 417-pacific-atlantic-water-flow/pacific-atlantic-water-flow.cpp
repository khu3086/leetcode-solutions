class Solution {
public:
    void dfs(vector<vector<int>>& h,vector<vector<bool>>& vis, int i, int j, int m, int n){
        if(i<0||i>=m||j<0||j>=n||vis[i][j]) return;
        vis[i][j]=true;
        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto d: dir){
            int x=i+d[0];
            int y=j+d[1];
            if(x>=0&&x<m&&y>=0&&y<n&&h[x][y]>=h[i][j]){
                dfs(h, vis, x, y, m, n);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i=0;i<n;i++){
            dfs(heights, pacific, 0, i, m, n);
        }
        for(int i=0;i<m;i++){
            dfs(heights, pacific, i, 0, m, n);
        }
        for(int i=0;i<n;i++){
            dfs(heights, atlantic, m-1, i, m, n);
        }
        for(int i=0;i<m;i++){
            dfs(heights, atlantic, i, n-1, m, n);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j]&&pacific[i][j])
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};