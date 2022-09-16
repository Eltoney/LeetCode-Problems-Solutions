class Solution {
    
    int dp(int i , int left ,  int n , int m ,vector<int>& nums, vector<int>& multipliers , vector<vector<int>> &mem ){
        if(i == m){
            return 0;
        }
        int &ret = mem[i][left];
        if(ret != -1e8){
            return ret;
        }
        int right = left + (n - 1) - i;
        int a = -1e8 , b = -1e8;
        a = dp(i + 1 , left + 1 , n , m , nums , multipliers , mem) + multipliers[i] * nums[left];
        b = dp(i + 1 , left , n , m , nums , multipliers , mem) + multipliers[i] * nums[right];
        ret = max(a , b);
        return ret;
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> mem(m , vector<int>(m, -1e8));
        int ans = dp(0 , 0 , n , m , nums , multipliers , mem);
        return ans;
    }
};