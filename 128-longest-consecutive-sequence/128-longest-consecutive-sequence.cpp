class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.size() == 0)
           return 0;
        sort(nums.begin() , nums.end());
        
        int best = 1 , cnt = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[i -1]){
                if(nums[i] == nums[i - 1] + 1){
                    cnt++;
                }else{
                    best = max(best , cnt);
                    cnt = 1;   
                }
            }
        }
        return max(best , cnt);
    }
};