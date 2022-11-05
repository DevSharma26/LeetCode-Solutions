//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int a[], int n, int k) {
        vector<int> f(k,0);
        for(int i=0;i<n;i++){
            f[a[i]%k]++;
        }
        unordered_map<int,int> m;
        int ans=0;
        for(int i=1;i<k;i++){
            if(m.count(i))continue;
            if(i==k-i){
                if(f[i])ans++;
                m[i]++;
                continue;
            }
            ans+=max(f[i], f[k-i]);
            m[i]++;
            m[k-i]++;
        }
        if(f[0])ans++;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends