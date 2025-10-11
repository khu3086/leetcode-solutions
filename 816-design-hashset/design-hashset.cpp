class MyHashSet {
public:
    bitset<1000001> bset;
    MyHashSet() {
        bset.reset();
    }
    
    void add(int key) {
        bset.set(key);
    }
    
    void remove(int key) {
        bset.reset(key);
    }
    
    bool contains(int key) {
        return bset.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */