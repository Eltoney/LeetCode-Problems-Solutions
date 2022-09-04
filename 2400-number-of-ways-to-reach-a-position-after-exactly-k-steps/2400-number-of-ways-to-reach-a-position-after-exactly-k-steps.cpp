class Solution {
   
    int dp(int move , int k , int cur , int ed , int MOD , vector<vector<int>> &mem){
        
        if(move == k){
            return (cur == ed);
        }
        
        if(mem[move][cur] != -1){
            return mem[move][cur];
        }
        
        int a = dp(move + 1 , k , cur + 1 , ed , MOD , mem);
        int b = dp(move + 1 , k , cur - 1 , ed , MOD , mem);
        return mem[move][cur] = (a + b) % MOD;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> mem(k + 1 , vector<int>(100000 , -1));
        int MOD = (int)1e9 + 7;
        return dp(0 , k , startPos + 1000 , endPos + 1000 , MOD , mem)  % MOD;
    }
};