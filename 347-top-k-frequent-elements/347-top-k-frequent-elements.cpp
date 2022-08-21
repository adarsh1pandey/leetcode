class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        vector<int> ans;
        int n = nums.size();
         unordered_map<int, int> ump;
        for (int i = 0; i < n; i++)
        {
            ump[nums[i]]++;
        }
        
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minH;
            
        for (auto it : ump)
        {
            minH.push({it.second, it.first});
            if (minH.size()> k)
            {
                minH.pop();
            }
        }
        
       while(!minH.empty())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
       
        return ans;
    }
};