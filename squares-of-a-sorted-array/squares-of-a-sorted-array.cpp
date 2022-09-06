class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
	int n = nums.size();
	int posId = 0;
	while (posId < n && nums[posId] < 0) {
		posId++;
	}
	int negId = posId - 1;
	vector<int> ans;
    

	while (negId >= 0 || posId < n) {
		if (negId < 0) {
			ans.push_back(nums[posId] * nums[posId]);
			posId++;
		} else if (posId >= n) {
			ans.push_back(nums[negId] * nums[negId]);
			negId--;
		} else if (abs(nums[negId]) < nums[posId]) {
			ans.push_back(nums[negId] * nums[negId]);
			negId--;
		} else {
			ans.push_back(nums[posId] * nums[posId]);
			posId++;
		}
	}

	return ans;
}
};