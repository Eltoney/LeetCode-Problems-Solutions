class Solution {
public:
    bool checkString(string s) {
        int a = -1 , b = -1;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'a'){
                a = i;
            }else if(b == -1){
                b = i;
            }
        }
        return (a == -1 || b == -1 || a < b);
    }
};