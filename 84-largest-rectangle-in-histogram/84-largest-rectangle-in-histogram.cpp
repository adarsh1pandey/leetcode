class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
       int n = heights.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> stack; // {element, index}
        
        for (int i = 0; i < n; ++i) { // adding index of first element smaller than element to its left at index i to left array
            if (stack.empty()) left[i] = -1;
            else if (stack.top().first < heights[i]) left[i] = stack.top().second;
            else if (stack.top().first >= heights[i]) {
                while (!stack.empty() && stack.top().first >= heights[i]) stack.pop();
                if (!stack.empty()) left[i] = stack.top().second;
                else left[i] = -1;
            }
            stack.push(make_pair(heights[i], i));
        }
        
        while(!stack.empty()) stack.pop();
        
        for (int i = n-1; i >= 0; --i) { // adding index of first element smaller than element to its right at index i to right array
            if (stack.empty()) right[i] = n;
            else if (stack.top().first < heights[i]) right[i] = stack.top().second;
            else if (stack.top().first >= heights[i]) {
                while (!stack.empty() && stack.top().first >= heights[i]) stack.pop();
                if (!stack.empty()) right[i] = stack.top().second;
                else right[i] = n;
            }
            stack.push(make_pair(heights[i], i));
        }
        
        int area = 0;
        for (int i = 0; i < n; ++i) {
            area = max(area, (right[i] - left[i] - 1) * heights[i]);
        }
        return area;
    }
};