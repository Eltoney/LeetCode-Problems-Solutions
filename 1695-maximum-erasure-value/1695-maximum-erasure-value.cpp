class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int j = 0 , i = 0;
        map<int,int> cnt;
        int n = nums.size();
        int cur = 0 , ans = 0;
        while(j < n){
            cnt[nums[j]]++;
            cur += nums[j];
            while(cnt[nums[j]] > 1){
                cnt[nums[i]]--;
                cur -= nums[i++];
            }
            j++;
            ans = max(ans , cur);
        }
        return ans;
    }
};