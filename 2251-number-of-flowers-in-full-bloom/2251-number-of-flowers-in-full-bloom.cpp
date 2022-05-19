class Solution {
public:
vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
		vector<int> &persons) {
	map<int, int> mp;
	int n = flowers.size();
	for (int i = 0; i < n; i++) {
		mp[flowers[i][0]]++;
		mp[flowers[i][1] + 1]--;
	}
	vector<pair<int, int>> v;

	for (auto x : mp) {
		v.push_back( { x.first, x.second });
	}

	sort(v.begin(), v.end());

	int m = v.size();

	for (int i = 1; i < (int) v.size(); i++) {
		v[i].second += v[i - 1].second;
	}

	vector<int> days, cnt;
	for (int i = 0; i < m; i++) {
		days.push_back(v[i].first);
		cnt.push_back(v[i].second);
	}

	int s = persons.size();
	vector<int> ans(s);
	for (int i = 0; i < s; i++) {
		auto it = lower_bound(days.begin(), days.end(), persons[i])
				- days.begin();
        if(it == m){
			ans[i] = cnt[m - 1];
			continue;
		}
		if (persons[i] < days[it]) {
			it--;
		}
		if (it < 0) {
			ans[i] = 0;
		} else {
			ans[i] = cnt[it];
		}
	}
	return ans;
}

};