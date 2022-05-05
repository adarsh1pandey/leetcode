// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here 
        for(int i = 1; i < S.size(); i++)
        {
            string start, end;
            start = S.substr(0, i);
            end = S.substr(i);
            int x, y;
            x = stoi(start);
            y = stoi(end);
            if (x % a == 0 && y % b == 0)
            {
                return start+" "+end;
            }
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends