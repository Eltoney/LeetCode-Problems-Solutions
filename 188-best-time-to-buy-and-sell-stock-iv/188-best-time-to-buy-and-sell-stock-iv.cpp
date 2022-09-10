class Solution {
    int dp(int i , int trans , int state , int n , int k , vector<vector<vector<int>>> &mem , vector<int> &prices){
        if(i == n || trans == k){
            return 0;
        }
        int &ret = mem[i][trans][state];
        if(ret != -1){
            return ret;
        }
        int a = -1e6, b=-1e6;
        a = dp(i + 1 , trans , state , n , k , mem , prices);
        if(state == 1){
            b = dp(i + 1 , trans + 1, 0 , n , k , mem , prices) + prices[i];
        }else{
            b = dp(i + 1 , trans, 1 , n , k , mem , prices) - prices[i];
        }
        ret = max(a , b);
        return ret;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> mem(n + 9 , vector<vector<int>>(k + 9 , vector<int>(2 , -1)));
        int ans = dp(0, 0, 0, n, k, mem, prices);
        return ans;
    }
};