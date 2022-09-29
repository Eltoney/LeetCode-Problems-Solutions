class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> close;
        
        int n = arr.size();
        
        for(int i = 0 ; i < n ; i++){
            int diff = abs(x - arr[i]);
            close.push_back({diff , arr[i]});
        }
        
        sort(close.begin() , close.end());
        
        vector<int> ans(k);
        
        for(int i = 0 ; i < k ; i++){
            ans[i] = close[i].second;
        }
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};