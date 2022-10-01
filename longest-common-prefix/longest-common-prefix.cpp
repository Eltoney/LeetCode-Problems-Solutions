class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        for(int j = 0 ; j < strs[0].size() ; j++){
            int cnt = 0;
            for(int i = 0 ; i < n ; i++){
                if(j < strs[i].size() && strs[i][j] == strs[0][j]){
                    cnt++;
                }
            }
            if(cnt == n){
                ans++;
            }else{
                break;
            }
        }
        string x = "";
        for(int i = 0 ; i < ans ; i++){
            x += strs[0][i];
        }
        return x;
    }
};