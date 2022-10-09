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
    unordered_map<int,bool> mp;
    
    bool DFS(TreeNode* root , int k){
        if(root == NULL){
            return 0;
        }
        if(mp[k - root -> val] == 1){
            return 1;
        }
        mp[root-> val] = 1;
        return (DFS(root -> left , k) | DFS(root -> right , k));
        
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return DFS(root , k);
    }
};