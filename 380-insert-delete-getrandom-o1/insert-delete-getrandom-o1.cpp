class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]=nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        //swap last and required ele
        int n=nums.size();
        int num=nums[mp[val]];
        int idx=mp[val];
        int swapped=nums[n-1];
        swap(nums[mp[val]], nums[n-1]);
        nums.pop_back();
        mp.erase(num);
        if(num != swapped)
        mp[swapped] = idx;
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */