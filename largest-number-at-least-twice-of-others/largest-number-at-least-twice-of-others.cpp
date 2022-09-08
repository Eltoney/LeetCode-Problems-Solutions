class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = -1;
        int id = -1;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(mx < nums[i]){
                mx = nums[i];
                id = i;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(id == i){
                continue;
            }
            if(nums[i] * 2 > mx){
                return -1;
            }
        }
        return id;
    }
};