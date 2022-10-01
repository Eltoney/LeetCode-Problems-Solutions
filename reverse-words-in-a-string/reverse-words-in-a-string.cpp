class Solution {
public:
    string reverseWords(string s) {
        int i = 0 , j = s.size() - 1;
        char temp;
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++,j--;
        }
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' ' && (ans.size() == 0 || ans.back() == ' ')){
                continue;
            }
            ans += s[i];
        }
        while(ans.back() == ' '){
            ans.pop_back();
        }
        ans += ' ';
        string lastAns = "";
        string cur = "";
        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == ' '){
                for(int j = cur.size() - 1 ; j >= 0 ; j--){
                    lastAns += cur[j];
                }
                cur = "";
                lastAns += ' ';
            }else{
                cur += ans[i];
            }
        }
        lastAns.pop_back();
        return lastAns;
    }
};