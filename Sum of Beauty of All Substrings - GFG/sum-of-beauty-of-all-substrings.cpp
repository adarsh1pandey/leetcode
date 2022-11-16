//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beauty(vector<int> &v)
    {
        int lf = 1e9;
        int mf = -1;
        for (int i = 0; i < 26; i++)
        {
            mf = max(mf, v[i]);
            if (v[i] >= 1)
            {
                lf = min(lf, v[i]);
            }
        }
        return mf - lf;
    }
    int beautySum(string s) {
        // Your code goes here
        int res = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> v(26, 0);
            for (int j = i; j < s.size(); j++)
            {
                v[s[j] - 'a']++;
                res += beauty(v);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends