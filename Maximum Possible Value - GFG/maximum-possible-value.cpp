//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long minLength = INT_MAX, total_stick = 0, total_perimeter = 0;
        
        for (int i = 0; i < N; i++){
            if (B[i] % 2 == 1) B[i]--;
            if (B[i] >= 2) minLength = min(minLength, long(A[i]));
            
            total_stick += B[i];
            total_perimeter += B[i] * A[i];
        }
        if (total_stick % 4 != 0) total_perimeter -= 2 * minLength;
        
        return total_perimeter;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends