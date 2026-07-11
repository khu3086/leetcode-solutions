class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py) return;
        parent[py]=px;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        unordered_map<int, pair<int, int>> mp;
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto e: edges){
            unite(e[0], e[1]);
        }
        for(auto e: edges){
            //count number of dges in a component
            mp[find(e[0])].first++;
        }
        //count number of nodes
        for(int i=0;i<n;i++){
            mp[find(i)].second++;
        }
        int ans=0;
        for(auto m:mp){
            int e=m.second.first;
            int n=m.second.second;
            if(e==(n*(n-1))/2) ans++;
        }
        return ans;
        
    }
};