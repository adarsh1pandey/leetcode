class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int res = 0;
        
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                res = mid + 1;
                start = mid + 1;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
        }
        return res;
        
    }
};