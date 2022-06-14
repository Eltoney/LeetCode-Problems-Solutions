/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long  st = 1 , ed = n , mid;
        while(st <= ed){
            mid = (st + ed) / 2;
            if(guess(mid) == 0){
                return mid;
            }else if(guess(mid) == 1){
                st = mid + 1;
            }else{
                ed = mid - 1;
            }
        }
        return n;
    }
};