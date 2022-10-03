class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cur = -1 , need = 0 , cnt = 0 , tot = 1e9;
        int n = colors.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(cur != colors[i]){
                ans += (cnt > 1) * (tot - need);
                cur = colors[i];
                tot  = neededTime[i];
                need = neededTime[i];
                cnt = 1;
            }else{
                cnt++;
                need = max(need , neededTime[i]);
                tot += neededTime[i];
            }
        }
        ans += (cnt > 1) * (tot - need);
        return ans;
    }
};