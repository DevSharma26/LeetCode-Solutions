//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[a[i]]++;
        }
        if(mpp.size()==1){
            return n;
        }
        int odd=0,even=0;
        for(auto it:mpp){
            if(it.second%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even==1 || even==2){
            return 1;
        }
        return 2;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends