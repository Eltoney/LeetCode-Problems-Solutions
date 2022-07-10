class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n = cost.size();
        int s1 = 0 , s2 = 0;
        
        for(int i = 2 ; i <= n ; i++){
            int temp = s1;
            s1 = min(s1 + cost[i - 1] , s2 + cost[i - 2]);
            s2 = temp;
        }
        
        return s1;
    }
};