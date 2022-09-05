class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3){
            return 0;
        }
        int n = arr.size();
        int i = 1;
        while(i < n && arr[i - 1] < arr[i]){
            i++;
        }
        if(i == n || i == 1){
            return 0;
        }
        while(i < n && arr[i - 1] > arr[i]){
            i++;
        }
        return (i == n);
    }
};