class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
        {
            return "";
        }
        int start = 0;
        int end = m[key].size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (m[key][mid].first < timestamp)
            {
                start = mid + 1;
            }
            else if (m[key][mid].first > timestamp)
            {
                end = mid - 1;
            }
            else 
            {
                return m[key][mid].second;
            }
        }
        if (end >= 0)
        {
            return m[key][end].second;
        }    
        return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> m;
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */