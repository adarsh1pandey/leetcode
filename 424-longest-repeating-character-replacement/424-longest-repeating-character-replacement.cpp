class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxCount = 0;
        int result = 0;
        unordered_map<char, int> mp;
        
        while (j < n)
        {
            mp[s[j]]++;
            
            maxCount = max(maxCount, mp[s[j]]);
            
            if (j - i + 1 - maxCount > k)
            {
                mp[s[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};