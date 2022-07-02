class Solution {
    int MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin() , horizontalCuts.end());
        int n = horizontalCuts.size();
        int mxH = horizontalCuts[0];
        for(int i = 1 ; i < n ; i++){
            mxH = max(mxH , horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        mxH = max(mxH , h - horizontalCuts[n - 1]);
        
        sort(verticalCuts.begin() , verticalCuts.end());
        int m = verticalCuts.size();
        int mxW = verticalCuts[0];
        for(int i = 1 ; i < m ; i++){
            mxW = max(mxW , verticalCuts[i] - verticalCuts[i - 1]);
        }
        mxW = max(mxW , w - verticalCuts[m - 1]);
        //cout<<mxH<<" "<<mxW<<'\n';
        int ans = (((long long) mxH % MOD) * (mxW % MOD)) % MOD;
        return ans;
        
    }
};