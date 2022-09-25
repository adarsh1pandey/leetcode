class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (um.find(target - nums[i]) != um.end())
            {
                ans.push_back(i);
                ans.push_back(um[target - nums[i]]);
                break;
            }
            else
            {
                um[nums[i]] = i;
            }
        }
        return ans;
    }
};