//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long

	ll countSubarray(int arr[], int n, int k) {
	    // code here
	    ll notRequired = 0;
	    ll ans = (long(n) * long (n + 1)) / 2;
	    
	    int i = 0;
	    while (i < n)
	    {
	        if (arr[i] > k)
	        {
	            i++;
	            continue;
	        }
	        
	        ll count = 0;
	        while (arr[i] <= k && i < n)
	        {
	            i++;
	            count++;
	        }
	        notRequired += (count * (count + 1))/2;
	    }
	    return ans - notRequired;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends