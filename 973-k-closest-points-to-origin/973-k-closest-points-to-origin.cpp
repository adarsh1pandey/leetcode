class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        
        priority_queue<pair<int, pair<int, int>>> maxH;
        
        int n = points.size();
        
        for (int i = 0; i < n; i++)
        {
            maxH.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        
        while (maxH.size() > 0)
        {
            pair<int, int> p = maxH.top().second;
            ans.push_back({p.first, p.second});
            maxH.pop();
        }
        return ans;
    }
};