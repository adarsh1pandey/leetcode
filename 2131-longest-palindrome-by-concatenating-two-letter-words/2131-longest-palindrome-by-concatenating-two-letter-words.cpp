class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> ump;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            ump[words[i]]++;
        }
        int ans = 0;
        bool flag = false;
        
        for (auto x: ump)
        {
            string s = x.first;
            string t = s;
            reverse(s.begin(), s.end());
            if (s == t)
            {
                ans += x.second / 2;
                if (x.second % 2)
                {
                    flag = true;
                }
            }
            else
            {
                if (ump.count(s))
                {
                    ans += min(x.second, ump[s]);
                    ump.erase(s);
                }
            }
        }
        ans = ans * 4;
        if (flag == true)
        {
            ans += 2;
        }
        return ans;
    }
};