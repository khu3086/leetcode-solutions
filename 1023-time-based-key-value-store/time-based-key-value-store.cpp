class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        //binary search on mp[key]
        int left=0;
        int right=mp[key].size()-1;
        string ans="";
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mp[key][mid].first==timestamp) return mp[key][mid].second;
            else if(mp[key][mid].first<timestamp){
               { left=mid+1; ans=mp[key][mid].second;}
            }else right=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */