class Solution {
    int negSeq(vector<int> &nums){
        vector<int> ans;
        int id = 0 , i = 1 , n = nums.size();
        ans.push_back(nums[0]);
        while(i < n ){
            if(id % 2 == 0){
                if(nums[i] < ans.back()){
                    ans.push_back(nums[i]);
                    id++;
                }else{
                    ans.back() = nums[i];
                }
            }else{
                if(nums[i] > ans.back()){
                    ans.push_back(nums[i]);
                    id++;
                }else{
                    ans.back() = nums[i];
                }
            }
            i++;
        }
        return ans.size();
    }
    
    int posSeq(vector<int> &nums){
         vector<int> ans;
        int id = 0 , i = 1 , n = nums.size();
        ans.push_back(nums[0]);
        while(i < n ){
            if(id % 2 == 0){
                if(nums[i] > ans.back()){
                    ans.push_back(nums[i]);
                    id++;
                }else{
                    ans.back() = nums[i];
                }
            }else{
                if(nums[i] < ans.back()){
                    ans.push_back(nums[i]);
                    id++;
                }else{
                    ans.back() = nums[i];
                }
            }
            i++;
        }
        return ans.size();
    }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
       return max(posSeq(nums) , negSeq(nums));
    }
};