class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e5;
        int n = nums.size();
        int cur = -1e5;
        for(int i = 0 ; i < n ; i++){
            cur = max(cur + nums[i] , nums[i]);
            ans = max(ans, cur);
        }
        return ans;
    }
};