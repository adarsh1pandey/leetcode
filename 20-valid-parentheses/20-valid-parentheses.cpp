class Solution {
public:
    bool isValid(string s) {
       int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            
            if (st.empty())
            {
                return false;
            }
            else if (s[i] == ')' && !st.empty())
            {
                if (st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == '}' && !st.empty())
            {
                if (st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == ']' && !st.empty())
            {
                if (st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};