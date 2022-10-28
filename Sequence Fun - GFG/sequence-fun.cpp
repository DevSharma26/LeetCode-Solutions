//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	int NthTerm(int n){
		    int mod = 1e9 + 7;
		    uint64_t val = 2;
		    if(n == 1){
		        return val;
		    }
		    uint64_t i = 1;
		    uint64_t m = 2;
		    while(i < n){
		        uint64_t curr = ((val*m)%mod + 1)%mod;
		        val = curr;
		        m++;
		        i++;
		    }
		    return val;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends