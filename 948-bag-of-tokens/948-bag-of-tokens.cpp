class Solution {
   
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int score = 0;
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>> minHeap;
        for(int i = 0 ; i < n ; i++){
            maxHeap.push({tokens[i] , i});
            minHeap.push({tokens[i] * -1 , i});
        }
        vector<bool> vis(n);
        int i = 0;
        int mxScore = 0;
        while(i < n){
            while(!minHeap.empty() && vis[minHeap.top().second]){
                minHeap.pop();
            }
            while(!minHeap.empty() && power >= minHeap.top().first * -1){
                power -= minHeap.top().first * -1;
                vis[minHeap.top().second] = 1;
                score++;
                while(!minHeap.empty() && vis[minHeap.top().second]){
                    minHeap.pop();
                }
            }
            mxScore = max(mxScore , score);
            while(!maxHeap.empty() && vis[maxHeap.top().second]){
                maxHeap.pop();
            }
            if(score > 0 && !maxHeap.empty()){
                power += maxHeap.top().first;
                vis[maxHeap.top().second] = 1;
                score--;
            }
            mxScore = max(mxScore , score);
            
            i++;
        }
        return mxScore;
    }
};