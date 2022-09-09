class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin() , properties.end());
        int ans = 0;
        int n = properties.size();
        int cur = n - 1;
        int j = cur;
        int mx = INT_MIN;
        while(cur >= 0){
            while(j >= 0 && properties[j][0] == properties[cur][0]){
                ans += properties[j][1] < mx; 
                j--;
            }
            while(cur > j){
                mx = max(mx , properties[cur][1]);
                cur--;
            }
        }
        return ans;
    }
};