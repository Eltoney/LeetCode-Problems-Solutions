class Solution {
    static bool cmp(pair<int,int> a , pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    int MOD = int(1e9) + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long sum = 0;
        long long ans = 0;
        vector<pair<int,int>> eng(n);
        for(int i = 0 ; i < n ; i++){
            eng[i].first = speed[i];
            eng[i].second = efficiency[i];
        }
        sort(eng.begin() , eng.end() , cmp);
        priority_queue<int> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(-1 * eng[i].first);
            sum += eng[i].first;
            if(pq.size() > k){
                sum -= pq.top() * -1;
                pq.pop();
            }
            ans = max(ans , sum * eng[i].second);
        }
        return ans % MOD;
    }
};