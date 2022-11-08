//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  
  int n = src.length();
  string ans = "";
  for (int i = 0; i < n; i++)
  {
      int count = 1;
      while (src[i] == src[i+ 1] && i < n - 1)
      {
          count++;
          i++;
      }
      ans += src[i] + to_string(count);
  }
  return ans;
}     
 
