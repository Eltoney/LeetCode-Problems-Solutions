class Solution {
    bool isValidTriangle(int a , int b , int c){
        return (a + b) > c;
    }
    
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i = 2 ; i < n ; i++){
            if(isValidTriangle(nums[i - 2] , nums[i - 1] , nums[i])){
                ans = max(ans , nums[i - 2] + nums[i - 1] + nums[i]);
            }
        }
        return ans;
    }
};