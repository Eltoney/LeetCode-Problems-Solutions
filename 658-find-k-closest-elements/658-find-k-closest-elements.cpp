class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = -1 , j = -1;
        int n = arr.size();
        vector<int> ans;
        
        auto it = lower_bound(arr.begin() , arr.end() , x) - arr.begin();
        if(it < n && arr[it] == x){
            ans.push_back(arr[it]);
            k--;
            i = it - 1 , j = it + 1;
        }else{
            i = it - 1 , j = it;
        }
       
        
        while(k){
            if(i < 0){
                ans.push_back(arr[j++]);
            }else if(j >= n){
                ans.push_back(arr[i--]);
            }else if(abs(arr[i] - x) <= abs(arr[j] - x)){
                ans.push_back(arr[i--]);
            }else{
                ans.push_back(arr[j++]);
            }
            k--;
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};