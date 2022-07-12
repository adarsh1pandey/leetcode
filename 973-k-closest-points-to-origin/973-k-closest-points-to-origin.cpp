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
            vector<int> v;
            v.push_back(maxH.top().second.first);
            v.push_back(maxH.top().second.second);
            ans.push_back(v);
            maxH.pop();
        }
        return ans;
    }
};