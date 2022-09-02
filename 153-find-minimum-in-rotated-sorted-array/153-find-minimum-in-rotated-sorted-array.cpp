class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;
        
        while (start <= end)
        {
            int mid = start + (end - start)/ 2;
            
            if (nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return nums[end];
            
    }
};