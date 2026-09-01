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
    //if already cloned (in case of cyclic graph), don't clone again otherwise recursive loop
    //this map keeps track of what cloned already
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        if(mp.count(node)){
            return mp[node];
        }
        Node* copy = new Node(node->val);
        mp[node]=copy;
        for(Node* nei:node->neighbors){
            copy->neighbors.push_back(cloneGraph(nei));
        }
        return copy;
    }
};