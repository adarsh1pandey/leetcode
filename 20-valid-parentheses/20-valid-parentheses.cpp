class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> stk;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '('|| s[i] == '{'|| s[i] == '[')
            {
                stk.push(s[i]);
                
            }
            else if (stk.empty())
            {
                return false;
            }
            else if (s[i] == ')' && !stk.empty())
            {
                if (stk.top() != '(')
                {
                    return false;
                }
                stk.pop();
            }
            else if (s[i] == '}' && !stk.empty())
            {
                if (stk.top() != '{')
                {
                    return false;
                }
                stk.pop();
            }
            else if (s[i] == ']' && !stk.empty())
            {
                if (stk.top() != '[')
                {
                    return false;
                }
                stk.pop();
            }
        }
        if (stk.empty())
        {
            return true;
            
        }
        else
        {
            return false;
        }
        
    }
};