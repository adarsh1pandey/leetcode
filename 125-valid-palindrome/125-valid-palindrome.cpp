class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string a;
        int i = 0;
        int j = 0;
        int count = 0;
        while ( i < n)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')
            {
                count++;
                s[j] = tolower(s[i]);
                a = s;
                j++;
                i++;
            }
            else
            {
                i++;;
            }
        }
       
        i = 0;
        j = count - 1;
        while (i < j)
        {
            cout << s[i] << s[j];
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        
        return true;
    }
};