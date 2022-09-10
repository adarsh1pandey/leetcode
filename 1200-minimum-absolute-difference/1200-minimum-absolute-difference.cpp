class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
        vector<vector<int>> ans;
        int n=v.size();
        sort(v.begin(), v.end());
        int mi=INT_MAX;
        for (int i=1 ; i<n ; i++)
            mi = min(v[i]-v[i-1], mi);
        
        for (int i=1 ; i<n ; i++)
        {
            if (v[i]-v[i-1] == mi)
                ans.push_back({v[i-1], v[i]});
        }    
        
        return ans;
    }
};