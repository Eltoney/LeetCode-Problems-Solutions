class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int oddStPointer = n - 1;
        while(oddStPointer >= 0 && nums[oddStPointer] % 2){
            oddStPointer--;
        }
        
        if(oddStPointer < 0){
            return nums;
        }
        
        
        int i = 0 ;
        int temp;
        while(i < n){
            if(nums[i] % 2){
                temp = nums[i];
                nums[i] = nums[oddStPointer];
                nums[oddStPointer] = temp;
                while(i < oddStPointer && nums[oddStPointer] % 2){
                    oddStPointer--;
                }
            }
            if(i == oddStPointer){
                break;
            }
            i++;
        }
        return nums;
        
    }
};