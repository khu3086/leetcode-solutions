class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp; //key value times
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        string ans="";
        vector<pair<string, int>>& temp=mp[key];
        int high=temp.size()-1;
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(temp[mid].second<=timestamp){
                ans=temp[mid].first;
                low=mid+1;
            }
            else high=mid-1;
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