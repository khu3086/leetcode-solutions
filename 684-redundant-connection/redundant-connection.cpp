class Solution {
public:
    vector<int> rank, parent;
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return false;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py]){
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[x]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        vector<int> ans;
        for(auto edge:edges){
            if(!unite(edge[0], edge[1])) ans=edge;
        }
        return ans;
    }
};