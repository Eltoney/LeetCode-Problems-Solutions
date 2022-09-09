class Solution {
    static bool valid(int i , int j , int n , int m){
        return (i >= 0 && i < n && j >=0 && j < m);
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0 ;
        int j = 0 ;
        bool up = 1;
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        vector<int> ans;
        while(cnt < n * m){
            ans.push_back(mat[i][j]);
            if(up){
                i--,j++;
                if(!valid(i , j , n , m)){
                    i++,j--;
                    j++;
                    if(j == m){
                        j-- , i++;
                    }
                    up = !up;
                }
            }else{
                i++,j--;
                if(!valid(i , j , n , m)){
                    i--,j++;
                    i++;
                    if(i == n){
                        i-- , j++;
                    }
                    up = !up;
                }
            }
            cnt++;
            
        }
        return ans;
    }
};