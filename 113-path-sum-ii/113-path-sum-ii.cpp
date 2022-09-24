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
    vector<vector<int>> ans;
    
    void DFS(TreeNode* root , int targetSum , vector<int> path){
        if(root-> right == NULL && root -> left == NULL){
            if(root -> val == targetSum){
                path.push_back(root -> val);
                ans.push_back(path);
            }
            return;
        }
        path.push_back(root -> val);
        if(root -> right != NULL){
            DFS(root -> right , targetSum - root -> val , path);
        }
        if(root -> left != NULL){
            DFS(root -> left , targetSum - root -> val , path);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return ans;
        }
        vector<int> v;
        DFS(root , targetSum , v);
        return ans;
    }
};