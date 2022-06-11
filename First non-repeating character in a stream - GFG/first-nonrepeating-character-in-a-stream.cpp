// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		   vector<int> cnt(26, 0);
		    queue<char> q;
		    string ans;
		    
		    for (int i = 0; i < A.size(); i++)
		    {
		        cnt[A[i] - 'a']++;
		        q.push(A[i] - 'a');
		        while (cnt[q.front()] > 1 && !q.empty())
		        {
		            q.pop();
		        }
		        if (q.empty())
		        {
		            ans.push_back('#');
		        }
		        else
		        {
		            ans.push_back(q.front() + 'a');
		        }
		    }
		    return ans;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends