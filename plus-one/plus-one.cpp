class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin() , digits.end());
        digits[0]++;
        int n = digits.size();
        for(int i = 0 ; i < n ; i++){
            if(digits[i] > 9){
                digits[i] = digits[i] % 10;
                if(i == n - 1){
                    digits.push_back(1);
                }else{
                    digits[i + 1]++;
                }
            }
        }
        reverse(digits.begin() , digits.end());
        return digits;
    }
};