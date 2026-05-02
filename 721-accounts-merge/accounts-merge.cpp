class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        function<int(int)> find=[&](int x){
            if(parent[x]!=x) parent[x]=find(parent[x]);
            return parent[x];
        };

        auto unite=[&](int a, int b){
            parent[find(a)]=find(b);
        };

        unordered_map<string, int> emailToIdx;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(emailToIdx.find(email)!=emailToIdx.end()){
                    unite(i, emailToIdx[email]);
                }
                else{
                    emailToIdx[email]=i;
                }
            }
        }

        unordered_map<int, set<string>> mp;
        for(auto& [email, idx]: emailToIdx){
            int root=find(idx);
            mp[root].insert(email);
        }

        vector<vector<string>> ans;
        for(auto& [root, emails]: mp){
            vector<string> temp;
            temp.push_back(accounts[root][0]);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }
        return ans;
    }
};