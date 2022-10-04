class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> ump;
        
        for (int i = 0; i < nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        for (auto it: ump)
        {
            if (it.second > 1)
            {
                return it.first;
            }
        }
        return -1;
    }
};