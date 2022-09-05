class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> idx;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            int need = target - nums[i];
            if(idx.find(need) != idx.end()){
                ans.push_back(idx[need]);
                ans.push_back(i);
                return ans;
            }
            idx[nums[i]] = i;
        }
        return ans;
    }
};