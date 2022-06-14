class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin() , salary.end());
        int n = salary.size();
        int tot = 0;
        for(int i = 1 ; i + 1 < n ; i++){
            tot += salary[i];   
        }
        n-=2;
        return tot  * 1.0 / n;
    }
};