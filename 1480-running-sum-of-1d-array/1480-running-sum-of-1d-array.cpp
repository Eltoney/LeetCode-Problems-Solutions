class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> cum(n);
        for(int i = 0 ; i < n ; i++){
            cum[i] = nums[i];
            if(i){
                cum[i] += cum[i - 1];
            }
        }
        return cum;
    }
};