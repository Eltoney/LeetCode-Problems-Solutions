class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
	vector<int> ans = cells;
	map<vector<int>, int> vis;
	vector<vector<int>> pos;
	pos.push_back(cells);
	vis[cells] = pos.size();
	int cir, st;
	for (int i = 1; i <= n; i++) {
		vector<int> temp(8);
		for (int j = 1; j < 7; j++) {
			temp[j] = !(cells[j - 1] ^ cells[j + 1]);
		}

		if (vis.find(temp) == vis.end()) {
			pos.push_back(temp);
			vis[temp] = pos.size();
		} else {
			st = vis[temp] - 1;
			cir = pos.size() - st ;
			break;
		}
		cells = temp;
	}
	if (n < (int) pos.size()) {
		return pos[n];
	} else {
		n -= st ;
		return pos[st + n % cir];
	}
}
};