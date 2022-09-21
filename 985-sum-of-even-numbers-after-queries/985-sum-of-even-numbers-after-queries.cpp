class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        vector<int> ans(q);
        int tot = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i]  % 2 == 0){
                tot += nums[i];
            }
        }
        for(int i = 0 ; i < q ; i++){
            int id = queries[i][1];
            if(nums[id] % 2 == 0){
                tot -= nums[id];
            }
            nums[id] += queries[i][0];
            if(nums[id] % 2 == 0){
                tot += nums[id];
            }
            ans[i] = tot;
        }
        return ans;
    }
};