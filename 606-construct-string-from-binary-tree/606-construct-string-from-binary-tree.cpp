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
    string DFS(TreeNode* root){
        if(root == NULL){
            return "";
        }
        string cur = "";
        cur += '(';
        
            cur += to_string(root -> val);
        if(root -> left == NULL){
            if(root -> right != NULL){
                 cur += "()";
            }
        }else{
           cur += DFS(root -> left); 
        }
        cur += DFS(root -> right);
        cur += ')';
        return cur;
    }
    
public:
    string tree2str(TreeNode* root) {
        string ans = DFS(root);
        for(int i =0  ;i + 1< ans.size() ; i++){
            ans[i] = ans[i + 1];
        }
        ans.pop_back();
        ans.pop_back();
        return ans;
    }
};