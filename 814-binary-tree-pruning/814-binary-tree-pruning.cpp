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
    bool DFS(TreeNode* &root){
        if(root == NULL){
            return 0;
        }
        int id = root -> val | DFS(root -> left) | DFS(root -> right);
        if(!id){
            root = NULL;
        }
        return id;
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        DFS(root);
        return root;
    }
};