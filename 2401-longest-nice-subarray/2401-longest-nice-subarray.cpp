class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        int len = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            temp = nums[i] , len = 1;
            for(int j = i + 1 ; j < n ; j++){
                if((temp ^ nums[j] )== (temp + nums[j])){
                    len++;
                    temp += nums[j];
                }else{
                    break;
                }
            }
            ans = max(ans, len);
        }
        return ans;
    }
};