class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i = 1 ; i <= numRows ; i++){
            vector<int> curRow;
            for(int j = 1 ; j <= i ; j++){
                if(j == 1 || j == i)
                    curRow.push_back(1);
                else{
                    int lef = pascal[i - 2][j - 2];
                    int rig = pascal[i - 2][j - 1];
                    curRow.push_back(lef + rig);
                }
            }
            pascal.push_back(curRow);
        }
        return pascal;
    }
};