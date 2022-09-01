class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        
        helper(n, 0, 0, "", ans);
        return ans;
    }
    void helper(int size, int open, int close, string curr, vector<string> & ans)
    {
        if (curr.size() == 2*size)
        {
            ans.push_back(curr);
            return;
        }
        
        if (open < size)
        {
            helper(size, open + 1, close, curr + "(", ans);
        }
        if (close < open)
        {
            helper(size, open, close + 1, curr + ")", ans);
        }
    }
};