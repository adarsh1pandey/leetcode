//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        string s = A;
        int moves = 1;
        // check if size of A is less than B
        while (A.size() < B.size()){
            A += s;
            moves++;
        }
        // find function is used to find whether B is available in A or not 
        if (A.find(B) != -1){
            return moves;
        }
        // Now we add one more time to be safe 
        A += s;
        moves++;
        if (A.find(B) != -1){
            return moves;
        }
        // if we don't find then return -1
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends