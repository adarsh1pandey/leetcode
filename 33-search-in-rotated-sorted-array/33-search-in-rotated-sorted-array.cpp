class Solution {
public:
    int bs(vector<int>& nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int index = -1;
        while (start <= end)
        {
             int mid = start + (end - start)/2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            {
                index = mid;
                break;
            }
            else if (nums[mid] <= nums[end])
            {
                end = mid - 1;
            }
            else if (nums[start] <= nums[mid]) 
            {
                start = mid + 1;
            }
        }
        
        return max(bs(nums, 0, index - 1, target), bs(nums, index, n - 1, target));
        
    }
};