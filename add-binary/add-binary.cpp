class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.size() , m = b.size();
        int i = n - 1 , j = m - 1;
        int carry = 0;
        while(i >=0 || j >= 0){
            if(i < 0){
                if(carry && b[j] == '1'){
                    ans += '0';
                }else if(carry && b[j] == '0'){
                    ans += '1';
                    carry = 0;
                }else{
                    ans += b[j];
                }
            }else if(j < 0){
                if(carry && a[i] == '1'){
                    ans += '0';
                }else if(carry && a[i] == '0'){
                    ans += '1';
                    carry = 0;
                }else{
                    ans += a[i];
                }
            }else{
                int cur = (a[i] == '1') + (b[j] == '1') + carry;
                if(cur == 3){
                    ans += '1';
                    carry = 1;
                }else if(cur == 2){
                    ans += '0';
                    carry = 1;
                }else{
                    ans += cur ? '1' : '0';
                    carry = 0;
                }
            }
            i--,j--;
        }
        if(carry){
            ans += '1';
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};