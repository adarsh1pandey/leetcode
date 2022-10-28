class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> ump;
        vector<vector<string>> res;
        int n = strs.size();
        string temp;
        for(int i  = 0; i < n; i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            ump[temp].push_back(strs[i]);
        }
        
        for (auto it : ump)
        {
            res.push_back(it.second);
        }
        return res;
    
        
        
    }
};