class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //pair<int, pair<int, int>> //dist, x, y
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0]=0;
        pq.push({0, {0, 0}});
        vector<vector<int>> dir={{0,1}, {1,0}, {-1, 0}, {0, -1}};
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int currdist=top.first;
            int i=top.second.first;
            int j=top.second.second;
            if (currdist > dist[i][j]) continue;
            if(i == m-1 && j == n-1)
        return currdist;
            for(auto d:dir){
                int x=i+d[0]; int y=j+d[1];
                if(x>=0&&x<m&&y>=0&&y<n){
                    int newdist=max(abs(heights[i][j]-heights[x][y]), currdist);
                    if(newdist>=dist[x][y]) continue;
                    dist[x][y]=(newdist);
                    pq.push({dist[x][y], {x, y}});
                }
            }
        }
        return -1;
    }
};