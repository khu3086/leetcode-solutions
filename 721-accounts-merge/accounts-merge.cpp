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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> mp;
        int n=accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                mp[accounts[i][j]].push_back(i);
            }
        }
        for(auto m: mp){
            vector<int> uniting=m.second;
            for(int i=0;i<uniting.size();i++) unite(uniting[0], uniting[i]);
        }

        unordered_map<int, set<string>> groups;

    for(auto &m : mp){
        int p = find(m.second[0]);
        groups[p].insert(m.first);
    }

    vector<vector<string>> ans;

    for(auto &g : groups){
        vector<string> temp;
        temp.push_back(accounts[g.first][0]);

        for(auto &email : g.second)
            temp.push_back(email);

        ans.push_back(temp);
    }

    return ans;

    }
};