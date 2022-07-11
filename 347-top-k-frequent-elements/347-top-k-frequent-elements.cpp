class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        vector<int> ans;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> meanH;
        
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        for (auto it : mp)
        {
            meanH.push({it.second, it.first});
            
            if (meanH.size() > k)
            {
                meanH.pop();
            }
        }
        while (meanH.size() > 0)
        {
            ans.push_back(meanH.top().second);
            meanH.pop();
        }
        return ans;
    }
};