class Solution {
public:
    bool ispalindrome(string str)
    {
        int i = 0;
        int j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        
        
        for (int i = 2; i <= n - 2; i++)
        {
            string str = "";
            int nn = n;
            
            while (nn)
            {
                str += to_string(nn % i);
                nn = nn / i;
            }
            cout << str << endl;
            
            if (!ispalindrome(str))
            {
                return false;
            }
            
        }
        return true;
    }
};