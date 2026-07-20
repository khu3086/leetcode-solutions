class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {q.push({i, j}); vis[i][j]=0;}
            }
        }
        vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int count=0;
        while(!q.empty()){
            count++;
            int sz=q.size();
            //visit curr and nei, if 1 found in nei
            while(sz){
                auto top=q.front();
                int i=top.first;
                int j=top.second;
                q.pop();
                for(auto d: dir){
                    int x=i+d[0];
                    int y=j+d[1];
                    if(x>=0&&x<m&&y>=0&&y<n&&vis[x][y]==INT_MAX){
                        vis[x][y]=vis[i][j]+1;
                        q.push({x, y});
                    }
                }
                sz--;
            }
        }
        return vis;
    }
};