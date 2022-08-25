class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
       int maximum=0;
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        while(j<s.size())
        {
            mp[s[j]]++;
            if(mp.size()==j-i+1)
            {
                maximum=max(maximum,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maximum;
    }
};