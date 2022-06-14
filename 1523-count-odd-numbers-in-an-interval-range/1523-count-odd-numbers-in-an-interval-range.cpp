class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low) / 2;
        ans += (low % 2) || (high % 2);
       
        return ans;
    }
};