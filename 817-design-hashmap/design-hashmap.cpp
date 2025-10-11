class Node{
public:
    int key;
    int val;
    Node* next;
    Node(){
        key=-1;
        val=-1;
        next=nullptr;
    }
    Node(int k, int v){
        key=k; val=v; next=nullptr;
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
    
    void put(int key, int value) {
        int hashkey=key%1000;
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key) {curr->next->val=value;
            return;}
            curr=curr->next;
        }
        curr->next=new Node(key, value);
    }
    
    int get(int key) {
        int hashkey=key%1000;
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key) return curr->next->val;
            curr=curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hashkey=key%1000;
        Node* curr=map[hashkey];
        while(curr->next){
            if(curr->next->key==key){
                Node* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
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