class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int val = 0;
        int i = 0;
        int j = 0;
        
        unordered_map<int, int> mp;
        int n = fruits.size();
        
        while (j < n)
        {
            mp[fruits[j]]++;
            
           
            if (mp.size() <= 2)
            {
                val = max(val, j - i + 1);
                j++;
            }
            else if (mp.size() > 2)
            {
                while (mp.size() > 2)
                {
                    mp[fruits[i]]--;
                    if (mp[fruits[i]] == 0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return val;
    }
};