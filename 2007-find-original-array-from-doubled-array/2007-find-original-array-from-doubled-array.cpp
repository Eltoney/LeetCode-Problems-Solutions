class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> cnt(200009);
        sort(changed.begin() , changed.end());
        vector<int> ans;
        bool isOk = 1;
        int n = changed.size();
        for(int i = 0 ; i < n ; i++){
            cnt[changed[i]]++;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(cnt[changed[i]]){
                int need = changed[i] * 2;
                if(need == changed[i]){
                    if(cnt[need] > 1){
                        cnt[need] -= 2;
                        ans.push_back(need);
                    }else{
                        isOk = 0;
                        break;
                    }
                }else{
                    if(cnt[need] > 0){
                        ans.push_back(changed[i]);
                        cnt[need]--;
                        cnt[changed[i]]--;
                    }else{
                        isOk = 0;
                        break;
                    }
                }

            }
        }
        
        if(!isOk){
            ans = vector<int>();
        }
        return ans;
    }
};