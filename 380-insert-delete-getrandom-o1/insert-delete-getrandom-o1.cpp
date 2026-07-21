class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> num;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            num.push_back(val);
            int n=num.size();
            mp[val]=n-1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            int i=mp[val];
            int n=num.size();
            int temp=num[n-1];
            swap(num[i], num[n-1]);
            num.pop_back();
            mp[temp]=i;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return num[rand()%(num.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */