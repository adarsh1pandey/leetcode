class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (ump.count(nums[i]) > 0 && abs(ump[nums[i]] - i) <= k)
            {
                return true;
            }
            ump[nums[i]] = i;
        }
        return false;
    }
};