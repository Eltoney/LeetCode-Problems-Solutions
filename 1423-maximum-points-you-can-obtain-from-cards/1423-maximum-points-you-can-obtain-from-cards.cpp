class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> frontCum(n + 1) , backCum(n + 1);
        for(int i = 1 ; i <= n ; i++){
            frontCum[i] = cardPoints[i - 1] + frontCum[i - 1];
        }
        for(int i = 1 ; i <= n ;i++){
            backCum[i] = cardPoints[n - i] + backCum[i - 1];
        }
        int i = 0 , j = k;
        int ans = 0;
        while(i <= k){
            ans = max(ans , frontCum[i++] + backCum[j--]);
        }
        return ans;
    }
};