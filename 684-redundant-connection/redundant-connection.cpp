class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(x==parent[x]) return x;
        parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return false;
        int rx=rank[px];
        int ry=rank[py];
        if(rx>ry){
            parent[py]=px;
        }
        else if(rx<ry){
            parent[px]=py;
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto edge: edges){
            if(!unite(edge[0], edge[1])) return edge;
        }
        return {};

    }
};