class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n  = nums.size();
        auto it = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        if(it == n){
            return -1;
        }
        return (nums[it] == target ? it : -1);
    }
};