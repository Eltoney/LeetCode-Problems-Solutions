class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1 = INT_MAX;
        int mn2 = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] <= mn1){
                mn1 = nums[i];
            }else if(nums[i] <= mn2){
                mn2 = nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
};