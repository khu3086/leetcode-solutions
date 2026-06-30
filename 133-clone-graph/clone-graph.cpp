/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> mp;
        Node* newnode=new Node(node->val);
        mp[node]=newnode;
        q.push(node);
        while(!q.empty()){
            Node* top=q.front();
            q.pop();
            for(auto n: top->neighbors){
                if(mp.find(n)==mp.end()){
                    q.push(n);
                     Node*  newneigh=new Node(n->val);
                    mp[n]=newneigh;
                }
                mp[top]->neighbors.push_back(mp[n]);
            }
        }
        return mp[node];
    }
};