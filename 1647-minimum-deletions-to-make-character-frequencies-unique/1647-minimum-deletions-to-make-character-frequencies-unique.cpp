class Solution {
    int sum(int n){
        return (n + 1) * n / 2;
    }
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            freq[s[i] - 'a']++;
        }
        priority_queue<int> pq;
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]){
               pq.push(freq[i]);
            }
        }
        int ans=  0;
        while(pq.size() > 1){
            int cur = pq.top();
            pq.pop();
            if(cur == pq.top()){
                ans++;
                //pq.pop();
                if(cur - 1 > 0) {pq.push(cur - 1);}
            }
        }
        
        
        return ans;
    }
};