// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        
         int setBits=0,res=0;
    
        setBits= __builtin_popcount(b);
        stack<short int> s;
        while(a>0)
        {
            s.push(a%2);
            a=a/2;
        }
        vector<short int> m;   
         
        while(!s.empty())
        {
            if(s.top()==1 && setBits>0)
            {
                m.push_back(1);
                setBits--;
            }
            else
            {
                m.push_back(0);
            }
            s.pop();
        }
        for(int i=m.size()-1;i>=0 && setBits>0;i--)
        {
            if(m[i]==0)
            {
                m[i]=1;
                setBits--;
            }
        }
         
         
        int mask;
        for(int i=m.size()-1;i>=0;i--)
        {
            mask=1<<(m.size()-i-1);
             
            res+=m[i]*mask;
        }
        int n=m.size();
         
        while(setBits>0)
        {
            res+=1<<n;
            n++;
            setBits--;
        }
         
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends