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
        if(!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node]=new Node(node->val);
        while(!q.empty()){
            Node* topNode=q.front();
            q.pop();
            Node* newNode=mp[topNode];
            for(auto nei: topNode->neighbors){
                if(mp.find(nei)==mp.end()){
                    Node* temp=new Node(nei->val);
                    q.push(nei);
                    mp[nei]=temp;
                }
                newNode->neighbors.push_back(mp[nei]);
            }
        }
        return mp[node];
    }
};