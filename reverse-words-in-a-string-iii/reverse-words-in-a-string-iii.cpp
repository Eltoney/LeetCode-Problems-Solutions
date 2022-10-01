class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        s += " ";
        int n = s.size();
        string cur = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ' '){
                for(int j = cur.size() - 1 ; j >= 0 ; j--){
                    ans += cur[j];
                }
                
                if(i != n - 1){
                    ans += ' ';
                }
                cur = "";
            }else{
                cur += s[i];
            }
        }
        return ans;
    }
};