class Solution {
    int dp(int i , int j , string &s , vector<vector<int>> &memo){
        if(i >= j){
            return 0;
        }
        int &ret = memo[i][j];
        if(ret != -1){
            return ret;
        }
        if(s[i] == s[j]){
            ret = dp(i + 1 , j - 1 , s , memo);
        }else{
            ret = min(dp(i + 1 , j , s , memo) + 1 , dp(i , j - 1 , s , memo) + 1);
        }
        return ret;
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        int i = 0 , j = n - 1;
        vector<vector<int>> memo(n , vector<int>(n , - 1));
        int ans = dp(i , j , s , memo);
        return ans;
    }
};