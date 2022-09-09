class Solution {
    

public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin() , properties.end());
        set<int> st;
        int ans = 0;
        int n = properties.size();
        int cur = n - 1;
        int j = cur;
        while(cur >= 0){
            while(j >= 0 && properties[j][0] == properties[cur][0]){
                auto it = st.upper_bound(properties[j][1]);
                ans += (it != st.end());
                j--;
            }
            while(cur > j){
                st.insert(properties[cur][1]);
                cur--;
            }
        }
        return ans;
    }
};