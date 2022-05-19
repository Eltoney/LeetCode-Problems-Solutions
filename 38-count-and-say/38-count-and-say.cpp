class Solution {
   
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1 ; i < n ; i++){
            string cur = "";
            char c = '?';
            int cnt = 0;
            for(int j = 0 ; j < (int)ans.size() ; j++){
                if(ans[j] == c){
                    cnt++;
                }else{
                    if(cnt != 0){
                        string conv = to_string(cnt);
                        for(int k = 0; k < (int)conv.size() ; k++){
                            cur += conv[k];
                        }
                        cur += c;
                    }
                    c = ans[j];
                    cnt = 1;
                }
            }
           if(cnt != 0){
                        string conv = to_string(cnt);
                        for(int k = 0; k < (int)conv.size() ; k++){
                            cur += conv[k];
                        }
                        cur += c;
                    }
            ans  = cur;
           // cout<<ans<<endl;
        }
        return ans;
    }
    
};