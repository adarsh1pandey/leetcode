// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int value(long long A[], long long k, long long N)
    {
        priority_queue<long long> maxH;
        
        for (int i = 0; i < N; i++)
        {
            maxH.push(A[i]);
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        return maxH.top();
    }
    
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long sum = 0;
        
        long long first = value(A, K1 , N);
        long long second = value(A, K2, N);
        
        for (int i = 0; i < N; i++)
        {
            if (A[i] > first && A[i] < second)
            {
                sum += A[i];
            }
        }
        return sum;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends