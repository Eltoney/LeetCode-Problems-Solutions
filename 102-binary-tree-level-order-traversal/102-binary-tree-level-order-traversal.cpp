/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int,vector<int>> lev;
    
    void DFS(TreeNode *node , int level){
        if(node == NULL){
            return;
        }
        lev[level].push_back(node -> val);
        
        if(node -> left != NULL){
            DFS(node -> left , level + 1);
        }
        if(node -> right != NULL){
            DFS(node -> right , level + 1);
        }
        
    }
    
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root , 0);
        vector<vector<int>> ans;
        for(auto s : lev){
            ans.push_back(s.second);
        }
        return ans;
    }
};