class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin() , expected.end());
        int n = expected.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(expected[i] != heights[i]){
                ans++;
            }
        }
        return ans;
    }
};