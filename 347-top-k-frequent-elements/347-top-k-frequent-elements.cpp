class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            ump[nums[i]]++;
        }
        
        vector<vector<int>> bucket(n+1);
        
        for(auto it : ump)
        {
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        
        for (int i = n; i >= 0; i--)
        {
            if (res.size() >= k)
            {
                break;
            }
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            
        }
        return res;
        
    }
};