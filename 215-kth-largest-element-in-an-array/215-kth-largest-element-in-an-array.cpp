class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            minH.push(nums[i]);
            if (minH.size() > k)
            {
                minH.pop();
            }
        }
        return minH.top();
    }
};