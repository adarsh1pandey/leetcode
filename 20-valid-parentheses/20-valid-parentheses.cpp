class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            }
            else if (s[i] == '[') {
                stk.push('[');
            }
            else if (s[i] == '{') {
                stk.push('{');
            }
            
            else if (s[i] == ')' && !stk.empty()) {
                if (stk.top() == '(') {
                    stk.pop();
                }
                else {
                    stk.push(')');
                }
            }
            else if (s[i] == ']' && !stk.empty()) {
                if (stk.top() == '[') {
                    stk.pop();
                }
                else {
                    stk.push(']');
                }
                
            }
            else if (s[i] == '}' && !stk.empty()) {
                if (stk.top() == '{') {
                    stk.pop();
                }
                else {
                    stk.push('}');
                }
            }
            else {
                    stk.push(']');
                }
            
        }
        
        if (stk.empty()) {
            return true;
        }
        
        return false;
    }
};