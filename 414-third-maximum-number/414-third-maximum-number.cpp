#define ll long long
class Solution {

public:
    int thirdMax(vector<int>& nums) {
        ll thirdMx = INT_MIN - 3LL;
        ll firstMx = INT_MIN - 1LL;
        ll secondMx = INT_MIN - 2LL ;
    
        int n = nums.size();
        int edit = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != secondMx && nums[i] != firstMx && nums[i] >= thirdMx){
                edit++;
                if(nums[i] > secondMx){
                    thirdMx = secondMx;
                    if(nums[i] > firstMx){    
                        secondMx = firstMx;
                        firstMx = nums[i];
                    }else{
                        secondMx = nums[i];
                    }
                }else{
                    thirdMx = nums[i];
                }
            }
        }
        return (edit < 3 ? firstMx : thirdMx);
    }
};