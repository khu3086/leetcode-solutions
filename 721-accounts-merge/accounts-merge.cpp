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
        int n=accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        unordered_map<string, vector<int>> mp;
        for(int j=0;j<n;j++){
            vector<string> acc=accounts[j];
            for(int i=1;i<acc.size();i++)
            mp[acc[i]].push_back(j);
        }
        for(auto m: mp){
            vector<int> nodes=m.second;
            for(int i=0;i<nodes.size()-1;i++){
                unite(nodes[i], nodes[i+1]);
            }
        }
        unordered_map<int, vector<int>> grp;
        for(auto m: mp){
            vector<int> nodes=m.second;
            for(int i=0;i<nodes.size();i++){
                grp[find(nodes[i])].push_back(nodes[i]);
            }
        }
        vector<vector<string>> ans;
        for(auto g: grp){
            //ref node->g.first
            int ref=g.first;
            int num=g.second.size();
            vector<int> trav=g.second;
            set<string> st;
            for(int i=0;i<num;i++){
                for(int j=1;j<accounts[trav[i]].size();j++){
                    st.insert(accounts[trav[i]][j]);
                }
            }
            vector<string> temp;
            temp.push_back(accounts[ref][0]);
            for(auto str: st) temp.push_back(str);
            ans.push_back(temp);
        }
        return ans;
    }
};