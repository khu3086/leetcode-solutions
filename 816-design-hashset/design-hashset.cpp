class MyHashSet {
public:
    vector<vector<bool>> arr;
    MyHashSet() {
        arr.assign(10000, vector<bool>(10000, false));
    }
    
    void add(int key) {
        arr[key/1000][key%1000]=true;
    }
    
    void remove(int key) {
        arr[key/1000][key%1000]=false;
    }
    
    bool contains(int key) {
        return arr[key/1000][key%1000];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */