class Solution {
    int dp(int i , string s , vector<int>&mem){
        if(i == s.size()){
            return 1;
        }
        
        int &ret = mem[i];
        if(ret != -1){
            return ret;
        }
        ret = 0;
        if(s[i] != '0'){
            ret += dp(i + 1 , s, mem);
        }
        if(i + 1 < s.size()){
            string cur = "";
            cur += s[i];
            cur += s[i + 1];
            if(9 < stoi(cur) && stoi(cur) < 27){
                ret += dp(i + 2 , s , mem);
            }
        }
        return ret;
    }
public:
    int numDecodings(string s) {
        vector<int> mem(s.size() , -1);
        int ans = dp(0 , s , mem);
        return ans;
    }
};