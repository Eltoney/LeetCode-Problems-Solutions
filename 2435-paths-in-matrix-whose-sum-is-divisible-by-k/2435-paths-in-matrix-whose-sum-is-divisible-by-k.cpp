class Solution {
    const int MOD = (int)1e9 + 7;
    int dp(int i , int j , int cur , int n , int m , int k , vector<vector<vector<int>>> &memo , vector<vector<int>> &grid){
        if(i >= n ||  j >= m){
            return 0;
        }
        if(i == n - 1 && j == m - 1){
            int val = ((grid[i][j] % k) + (cur % k))% k;
            return (val % k == 0);
        }
        cur = cur % k;
        if(memo[i][j][cur] != -1){
            return memo[i][j][cur];
        }
        int &ret = memo[i][j][cur];
        int val = ((grid[i][j] % k) + (cur % k))% k;
        int a = dp(i , j + 1, val, n, m, k, memo, grid) % MOD;
        int b = dp(i + 1 , j, val, n, m, k, memo, grid) % MOD;
        ret = ((a % MOD) + (b % MOD))% MOD;
        return ret;
    }
   
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> memo(n , vector<vector<int>>(m , vector<int> (k , - 1)));
        int ans = dp(0 , 0 , 0 , n , m , k , memo , grid);
        return ans % MOD;
    }
};