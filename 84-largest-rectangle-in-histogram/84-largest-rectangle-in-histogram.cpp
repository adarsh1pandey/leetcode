class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left, right;
        stack <pair<int, int>> st;
        
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left.push_back(-1);
            }
            else if (!st.empty() && st.top().first < heights[i])
            {
                left.push_back(st.top().second);
            }
            else if (!st.empty() && st.top().first >= heights[i])
            {
                while (!st.empty() && st.top().first >= heights[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    left.push_back(-1);
                }
                else 
                {
                    left.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
        
        while (!st.empty())
        {
            st.pop();
        }
            
        
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.size() == 0)
            {
                right.push_back(n);
            }
            else if (!st.empty() && st.top().first < heights[i])
            {
                right.push_back(st.top().second);
            }
            else if (!st.empty() && st.top().first >= heights[i])
            {
                while (!st.empty() && st.top().first >= heights[i])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    right.push_back(n);
                }
                else 
                {
                    right.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        
        
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, heights[i] *(right[i] - left[i] - 1));
        }
        return ans;
    }
};