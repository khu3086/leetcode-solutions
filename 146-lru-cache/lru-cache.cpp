class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        head->next = tail;
head->prev = nullptr;
tail->prev = head;
tail->next = nullptr;
    }

    void addNode(Node* newNode){
        Node* temp=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=temp;
        temp->prev=newNode;
    }

    void deleteNode(Node* delNode){
        Node* last=delNode->prev;
        Node* next=delNode->next;
        last->next=next;
        next->prev=last;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int val=mp[key]->val;
            Node* temp=mp[key];
            deleteNode(temp);
            addNode(temp);
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }

        if(cap==mp.size()){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        Node* newNode=new Node(key, value);
            mp[key]=newNode;
            addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */