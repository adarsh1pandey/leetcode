class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        int num;
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.count(nums[i]) > 0)
            {
                num = nums[i];
            }
            seen[nums[i]] += 1;
        }
        return num;
    }
};