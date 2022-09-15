class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> cnt;
        int n = changed.size();
        for(int i = 0 ; i < n ; i++){
            cnt[changed[i]]++;
        }
        vector<int> ans;
        sort(changed.begin() , changed.end());
        for(int i = 0 ; i  < n ; i++){
            if(cnt[changed[i]] > 0){
                int need = changed[i] * 2;
                if(!need && cnt[need] > 1){
                    ans.push_back(need);
                    cnt[need] -= 2;
                }else if(need && cnt[need] > 0){
                    ans.push_back(changed[i]);
                    cnt[need]--;
                    cnt[changed[i]]--;
                }else{
                    ans = vector<int>();
                    break;
                }
            }
        }
        return ans;
    }
};