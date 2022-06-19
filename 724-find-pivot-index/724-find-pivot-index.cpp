class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s1 = 0 , tot = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            tot += nums[i];
        }
       // cout<<tot<<'\n';
        for(int i = 0 ; i < nums.size() ; i++){
            if(tot - nums[i] - s1 == s1){
                return i;
            }
            s1 += nums[i];
        }
        return -1;
    }
};