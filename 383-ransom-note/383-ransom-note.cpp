class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> mpm;
      
        
        for (int i = 0; i < magazine.size(); i++)
        {
            mpm[magazine[i]]++;
        }
        
        for (int i = 0; i < ransomNote.size(); i++)
        {
            mpm[ransomNote[i]]--;
        }
        for (auto it : mpm)
        {
            if (it.second < 0)
            {
                return false;
            }
        }
        return true;
    }
};