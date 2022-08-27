class Solution {
public:
    bool check(vector<int> &a, vector<int> &b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (m < n)
            return false;
        vector<int> fs1(26, 0);
        for (auto it: s1) 
        {
            fs1[it - 'a']++;
        }
        vector<int> fs2(26, 0);
        int i = 0;
        int j = 0;
        
        while(j < m)
        {
            fs2[s2[j] - 'a']++;
            
            if(j - i + 1 == n)
            {
                if (check(fs1, fs2))
                    return true;
                
            }
            if (j - i + 1 < n)
            {
                j++;
            }
            else if (j - i + 1 >= n)
            {
                fs2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
        
    }
};