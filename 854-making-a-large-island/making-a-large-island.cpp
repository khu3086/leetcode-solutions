class Solution {
public:
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
    vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& zeroes, int i, int j, int row, int col, int& sz){
        if(i>=row||i<0||j>=col||j<0) return;
        if(grid[i][j]==0){
            zeroes.push_back({i, j});
            return;
        }
        if(visited[i][j]) return;
        sz++;
        visited[i][j]=true;
        for(auto d: dir){
            int x=d[0]+i;
            int y=d[1]+j;
            dfs(grid, visited, zeroes, x, y, row, col, sz);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        //check surrounding islands of all 0s
        //map pair<int, int> -> sz island it is connecting
        unordered_map<pair<int, int>, vector<int>, PairHash> mp;
        int onecount=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        unordered_map<int, int> islandSize;
        int islandcount=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int sz=0;
                    onecount++;
                    vector<pair<int, int>> zeroes;
                    if(!visited[i][j])
                    {dfs(grid, visited, zeroes, i, j, row, col, sz);
                    islandcount++;
                    for(auto z: zeroes){
                        mp[z].push_back(islandcount);
                    }
                    islandSize[islandcount]=sz;
                    }
                }
            }
        }
        int maxIsland=0;
        for(auto m: mp){
            int currIsland=1;
            unordered_set<int> islands(m.second.begin(), m.second.end());
            for(auto s: islands) currIsland+=islandSize[s];
            maxIsland=max(maxIsland, currIsland);
        }
        if(onecount==row*col) return onecount;
        if(onecount==0) return 1;
        return maxIsland;
    }
};