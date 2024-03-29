class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            rightSum += nums[i];    
        }
        for(int i = 0 ; i < n ; i++){
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};