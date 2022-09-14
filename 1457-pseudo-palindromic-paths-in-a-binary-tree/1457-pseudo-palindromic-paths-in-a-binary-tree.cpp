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
    bool checkPal(vector<int> path){
        int o = 0;
        for(auto x : path){
            o += (x % 2);
        }
        return (o < 2);
    }
    
    int DFS(TreeNode *root , vector<int> path){
        if(root == NULL){
            return 0;
        }
        path[root -> val]++;
        if(root -> right == NULL && root -> left == NULL){
            return checkPal(path);
        }else{
             int ans = 0;
             ans += DFS(root -> left , path);
             ans += DFS(root -> right , path);
            return ans;
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10);
        int ans = DFS(root , path);
        return ans;
    }
};