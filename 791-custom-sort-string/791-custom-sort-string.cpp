class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> cnt(26);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            cnt[s[i] - 'a']++;
        }
        string ans = "";
        int mx =order.size();
        for(int i = 0 ; i < mx ; i++){
            for(int j = 0 ; j < cnt[order[i] - 'a'] ; j++){
                ans += order[i];
            }
            cnt[order[i] - 'a'] = 0;
        }
        for(int i = 0 ; i < 26 ; i++){
            for(int j = 0 ; j < cnt[i] ; j++){
                ans += (char(i + 'a'));
            }
        }
        return ans;
    }
};