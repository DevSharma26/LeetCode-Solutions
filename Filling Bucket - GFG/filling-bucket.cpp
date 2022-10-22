//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e8;
    int fillingBucket(int N) {
        if(N<=3) return N;
        int p1=1,p2=2;
        for(int i=1;i<=N-2;i++){
            int cur=(p1+p2)%mod;
            p1=p2;
            p2=cur;
        }
        return p2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends