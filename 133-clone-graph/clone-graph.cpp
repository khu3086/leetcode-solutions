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
         if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        map[node]=new Node(node->val);
        while(!q.empty()){
            Node* top=q.front();
            q.pop();
            for(auto x: top->neighbors){
                if(map.find(x)==map.end()){
                    map[x] = new Node(x->val);
                    q.push(x);  // ✅ push to queue for BFS
                }
                (map[top]->neighbors).push_back(map[x]);
            }

        }
        return map[node];

    }
};