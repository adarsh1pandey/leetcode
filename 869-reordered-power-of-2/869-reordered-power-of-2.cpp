class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
       string s = to_string(n);
        sort(s.begin(), s.end());
        
        for (int i = 0; i < 31; i++)
        {
            int a = pow(2, i);
            string b = to_string(a);
            sort(b.begin(), b.end());
            if (s == b)
            {
                return true;
            }
        }
        return false;
    }
};