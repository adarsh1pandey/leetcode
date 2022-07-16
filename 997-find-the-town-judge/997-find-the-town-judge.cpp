class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> umap(n + 1, 0);
        
        for(auto x: trust)
        {
            umap[x[0]]--;
            umap[x[1]]++;
        }
        
        for(int i = 1; i <= n; i++)
        {
            if (umap[i] == n - 1)
            {
                return i;
            }
        }
        
        return -1;
        
    }
};