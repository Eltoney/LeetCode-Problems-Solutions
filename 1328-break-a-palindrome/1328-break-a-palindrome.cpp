class Solution {
    
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1){
            return "";
        }
        int i = 0 , j = n - 1;
        while(i < j && palindrome[i] == palindrome[j] && palindrome[i] == 'a'){
            i++,j--;
        }
        if(i >= j){
            palindrome[n - 1] = 'b';
        }else{
            palindrome[i] = 'a';
        }
        return palindrome;
    }
};