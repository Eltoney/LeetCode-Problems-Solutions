class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int readPointer = 0 , writePointer = 0;
        int n = nums.size();
        while(readPointer < n){
            if(nums[readPointer] != 0){
                nums[writePointer] = nums[readPointer];
                writePointer++;
            }
            readPointer++;
        }
        while(writePointer < n){
            nums[writePointer] = 0;
            writePointer++;
        }
    }
};