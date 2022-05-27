class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> seen;
        int num;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.count(nums[i]) > 0)
            {
                num = nums[i];
            }
            seen[nums[i]] = true;
        }
        return num;
    }
};