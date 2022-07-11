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
    vector<int> ans;
    
    void dfs(TreeNode* node , int depth){
        if(node && depth == ans.size()){
            ans.push_back(node -> val);
        }
        if(node){
             if(node -> right){
            dfs(node -> right , depth + 1);
        }
        if(node -> left){
            dfs(node -> left , depth + 1);
        }
        }
       
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root ,  0);
        return ans;
    }
};