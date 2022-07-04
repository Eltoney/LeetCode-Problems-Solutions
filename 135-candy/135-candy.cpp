class Solution {
    long long sum(long long n){
        return (n + 1) * n / 2;
    }
    
public:
   long long candy(vector<int> &ratings) {
       int sum = 0;
       int n = ratings.size();
       vector<int> lft2Right(n , 1) , right2Lft(n , 1);
       for(int i = 1 ; i < n ; i++){
           if(ratings[i] > ratings[i - 1]){
               lft2Right[i] = lft2Right[i - 1] + 1;
           }
       }
       for(int i = n - 2 ; i >= 0 ; i--){
           if(ratings[i] > ratings[i + 1]){
               right2Lft[i] = right2Lft[i + 1] + 1;
           }
       }
       for(int i = 0 ; i< n ; i++){
           sum += max(lft2Right[i],right2Lft[i]);
       }
       return sum;
       
    }
};