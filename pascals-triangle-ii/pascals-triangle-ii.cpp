class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if(rowIndex == 0){
            ans.push_back(1);
        }else if(rowIndex == 1){
            ans.push_back(1);
            ans.push_back(1);      
        }else{
            ans.push_back(1);
            ans.push_back(1);
            for(int id = 2 ; id <= rowIndex ; id++){
                vector<int> temp;
                temp.push_back(1);
                for(int j = 1 ; j < ans.size() ; j++){
                    temp.push_back(ans[j] + ans[j - 1]);
                }
                temp.push_back(1);
                ans = temp;
            }
        }
        return ans;
    }
};