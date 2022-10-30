//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    // Code here
	    long long int dp[6]{0};
	    dp[0]=1;
	    long long alive=1;
	    for(int i=1;i<n;i++){
	        if(i>5){
	            alive-=dp[(i-6)%6];
	        }
	        dp[i%6]=alive*2;
	        alive+=dp[i%6];
	    }
	    return alive;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends