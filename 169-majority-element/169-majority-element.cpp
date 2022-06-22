class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int ele;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] > nums.size()/2)
            {
                ele =  nums[i];
            }
        }
        return ele;
        
    }
};