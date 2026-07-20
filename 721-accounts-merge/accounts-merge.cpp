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
            vector<int> temp=m.second;
            int sz=temp.size();
            for(int i=0;i<sz;i++){
                for(int j=i+1;j<sz;j++) unite(temp[i], temp[j]);
            }
        }
        unordered_map<int, vector<int>> grp;
        for(int i=0;i<n;i++){
            grp[find(i)].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto m: grp){
            vector<string> temp;
            set<string> temp2;
            temp.push_back(accounts[m.first][0]);
            int sz=m.second.size();
            vector<int> arr=m.second;
            for(int i=0;i<sz;i++){
                //curr idx=arr[i]
                for(int j=1;j<accounts[arr[i]].size();j++){
                    temp2.insert(accounts[arr[i]][j]);
                }
            }
            for(auto s: temp2) temp.push_back(s);
            ans.push_back(temp);
        }
        return ans;
    }
};