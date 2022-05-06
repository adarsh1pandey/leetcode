class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for (int x : s)
        {
            if (stk.size() == 0 || stk.back().first != x)
            {
                stk.push_back({x, 1});
            }
            else
            {
                stk.back().second++;
            }
            if (stk.back().second == k)
                stk.pop_back();
        }
        string res;
        for (auto p : stk)
        {
            res.append(p.second, p.first);
        }
        
        return res;
        
    }
};