class Node{
    public:
    int key;
    int value;
    Node* next;
    Node(){
        key=-1;
        value=-1;
        next=nullptr;
    }
    Node(int k, int v){
        key=k;
        value=v;
        next=nullptr;
    }
};

class MyHashMap {
public:
    vector<Node*> map;
    MyHashMap() {
        map.resize(1000);
        for(int i=0;i<1000;i++){
            map[i]=new Node();
        }
    }

    int hash_key(int key){
        return key%1000;
    }
    
    void put(int key, int value) {
        int hashkey=hash_key(key);
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key)
            {curr->next->value=value; return;}
            curr=curr->next;
        }
        curr->next=new Node(key, value);
    }
    
    int get(int key) {
        int hashkey=hash_key(key);
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key) return curr->next->value;
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashkey=hash_key(key);
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key){
                Node* temp=curr->next->next;
                delete(curr->next);
                curr->next=temp;
                return;
            }
            curr=curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */