class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int mxl[n];
        mxl[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            mxl[i] = max(mxl[i - 1], height[i]);
        }
        int mxr[n];
        mxr[n - 1] = height[n - 1];
        
        for (int i = n - 2; i >= 0; i--)
        {
            mxr[i] = max(mxr[i + 1], height[i]);
        }
        int width[n];
        int sum = 0;
        for (int i = 0; i < n ; i++)
        {
            width[i] = min(mxr[i], mxl[i]) - height[i];
            
        }
        for (int i = 0; i < n; i++)
        {
            sum += width[i];
        }
        return sum;
    }
};