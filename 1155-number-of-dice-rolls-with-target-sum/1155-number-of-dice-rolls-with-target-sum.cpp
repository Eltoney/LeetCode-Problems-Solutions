class Solution {
    int MOD = (int)1e9 + 7;
    int dp(int i ,int target ,  int n , int k , vector<vector<int>> &mem){
        if(target < 0){
            return 0;
        }
        if(i == n){
            return (target == 0);
        }
        
        int &ret = mem[i][target];
        if(ret != -1){
            return ret;
        }
        
        ret = 0;
        for(int j = 1 ; j <= k ; j++){
            ret = ((ret % MOD) + (dp(i + 1 , target - j , n , k , mem) % MOD)) % MOD;
        }
        return ret % MOD;
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> mem(n , vector<int>(target + 1 , -1));
        int ans = dp(0 , target , n , k , mem) % MOD;
        return ans;
    }
};