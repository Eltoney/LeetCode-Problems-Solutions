class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,char> mp ,mp1;
        for(int i = 0 ; i < n ; i++){
         
            if(mp.find(s[i]) != mp.end()){
                
                if(mp[s[i]] != t[i]){
                    return 0;
                }
                
            }
            if(mp1.find(t[i]) != mp1.end()){
                 if(mp1[t[i]] != s[i]){
                    return 0;
                }
            }
            mp[s[i]] = t[i] ;
            mp1[t[i]] = s[i];
        }
        return 1;
    }
};