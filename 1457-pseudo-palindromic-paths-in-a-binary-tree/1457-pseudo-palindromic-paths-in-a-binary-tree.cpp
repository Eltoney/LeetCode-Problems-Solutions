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
    int DFS(TreeNode *root ,int path){
        if(root == NULL){
            return 0;
        }
        path ^= (1 << (root -> val));
        if(root -> right == NULL && root -> left == NULL){
            return (path == 0 || path == pow(2 , (int)log2(path)));
        }else{
             int ans = 0;
             ans += DFS(root -> left , path);
             ans += DFS(root -> right , path);
            return ans;
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int path = 0;
        int ans = DFS(root , path);
        return ans;
    }
};