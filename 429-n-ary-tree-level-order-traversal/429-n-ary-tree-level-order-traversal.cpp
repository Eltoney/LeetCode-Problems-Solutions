/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        map<int,vector<int>> mp;
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        mp[0].push_back(root -> val);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            
            for(auto ch : cur.first -> children){
                mp[cur.second + 1].push_back(ch -> val);
                q.push({ch , cur.second + 1});
            }
        }
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};