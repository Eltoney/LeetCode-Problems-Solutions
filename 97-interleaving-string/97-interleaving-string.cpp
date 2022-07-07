class Solution { 
    
    string S1 , S2 , S3;
    bool vis[101][101][201];
    int res[101][101][201];
    bool dp(int i , int j , int k , int N ,int M ,int P){
        if(N + M != P){
            return 0;
        }
        if(k == P){
            return 1;
        }else if(i == N && j == M){
            return 0;
        }
        bool &ret = vis[i][j][k];
        if(ret){
            return res[i][j][k];
        }
        ret = 1;
        res[i][j][k] = 0;
        if(i < N && S1[i] == S3[k]){
            res[i][j][k] |= dp(i + 1 , j , k + 1 , N , M , P);
        }
        if(j < M && S2[j] == S3[k]){
            res[i][j][k] |= dp(i , j + 1 , k + 1 , N , M , P);
        }
        return res[i][j][k];
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        S1 = s1 , S2 = s2 , S3 = s3;
        return dp(0 , 0 ,0 , s1.size() , s2.size() , s3.size());
    }
};