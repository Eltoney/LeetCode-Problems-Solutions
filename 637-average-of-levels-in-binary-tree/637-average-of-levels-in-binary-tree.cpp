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
    
    void DFS(TreeNode* root , int lev,vector<long long> &levels , vector<int> &nodeCnt){
        if(root == NULL){
            return;
        }
        levels[lev] += root -> val;
        nodeCnt[lev]++;
        DFS(root -> left , lev + 1,levels,nodeCnt);
        DFS(root -> right, lev + 1,levels,nodeCnt);
        
    }
    
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
       vector<long long> levels(10009 , 0);
       vector<int> nodeCnt(10009 , 0);
        
        
       DFS(root , 0 , levels , nodeCnt);
       
       for(int i = 0 ; i <10009 ; i++){
           if(nodeCnt[i]){
               ans.push_back(levels[i] * 1.0 / nodeCnt[i]);
           }
       } 
        return ans;
    }
};