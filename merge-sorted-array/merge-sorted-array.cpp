class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n){
            int i = 0 , j = 0 , temp;
        while(i < m + n){
            if(nums1[i] == 0 && i >= m){
                nums1[i] = nums2[j];
                j++;
            }else if(nums2[j] < nums1[i]){
                temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                int k = j + 1;
                while(k < n && nums2[k] < nums2[k - 1]){
                    temp = nums2[k - 1];
                    nums2[k - 1] = nums2[k];
                    nums2[k] = temp;
                    k++;
                }
            }
            i++;
        }
        }
        
    }
};