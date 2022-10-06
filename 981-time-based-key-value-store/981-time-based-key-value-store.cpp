class TimeMap {
    int bsTimestamp(vector<pair<int,string>> & v , int x){
        int st = 0 , ed = v.size() - 1 , ans = -1 ,  mid;
        while(st <= ed){
            mid = (st + ed) / 2;
            if(v[mid].first <= x){
                ans = max(ans , mid);
                st = mid + 1;
            }else{
                ed = mid - 1;
            }
        }
        return ans;
    }
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        pair<int,string> cur = {timestamp , ""};
        int id = bsTimestamp(mp[key] , timestamp);
        if(id == -1){
            return "";
        }
        return mp[key][id].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */