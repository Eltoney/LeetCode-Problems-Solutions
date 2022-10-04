class Solution {
    bool DFS(TreeNode* node , int need){
        if(node == NULL){
            return 0;
        }
        if(node -> right == NULL && node -> left == NULL){
            need -= (node -> val);
            return (need == 0);
        }
        return (DFS(node -> left , need - node -> val) | DFS(node -> right , need - node -> val));
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return DFS(root , targetSum);
    }
};