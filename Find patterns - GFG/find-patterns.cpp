//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
    int res = 0, sz = W.size();
    vector<bool> visited(S.size() + 1, false);
    for(int x = 0; x < S.size(); x++){
        int y = x, ct = 0;
        for(y = x, ct = 0; y < S.size() and ct < sz; y++){
            if(visited[y] == false and W[ct] == S[y]){
                visited[y] = true;
                ct++;
            }
        }
        if(ct == sz){
            res++;
        }
    }
    return res;
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends