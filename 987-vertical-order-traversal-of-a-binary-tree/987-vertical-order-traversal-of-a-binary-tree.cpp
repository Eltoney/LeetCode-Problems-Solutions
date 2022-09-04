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
     map<int,vector<pair<int,int>>> mp;
    
    void DFS(TreeNode* root , int row , int col){
        if(root == NULL){
            return;
        }
        mp[col].push_back({row,root -> val});
        DFS(root -> left , row + 1 , col - 1);
        DFS(root -> right, row + 1 , col + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       DFS(root , 0 , 0);
        vector<vector<int>> ans;
        for(auto x : mp){
            if(x.second.size()){
                sort(x.second.begin() , x.second.end());
                vector<int> temp;
                for(auto cc : x.second){
                    temp.push_back(cc.second);
                }
                ans.push_back(temp);
            }

        }
        return ans;
    }
};