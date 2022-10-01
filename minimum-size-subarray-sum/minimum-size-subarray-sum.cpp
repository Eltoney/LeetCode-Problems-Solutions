class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        for(int i = 0 ; i < n ; i++){
            prefix[i] = nums[i];
            if(i){
                prefix[i] += prefix[i - 1];
            }
        }
        int ans = n + 1;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(prefix.begin() , prefix.end() , (i == 0 ? 0 : prefix[i - 1]) + target);
            if(it != prefix.end()){
                int len = it - prefix.begin();
                ans = min(ans , len - i + 1);
            }
        }
        return (ans == n + 1 ? 0 : ans);
        
    }
};