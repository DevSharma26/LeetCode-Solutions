//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>>ans;
        map<char,set<string>>m;
        for(int i =0;i<n;i++){
            string cont = contact[i];
            m[cont[0]].insert(contact[i]);
        }
        int len = s.length();
        for(int i = 0;i<len;i++){
            string str = s.substr(0,i+1);
            vector<string>temp;
            for(auto sr : m[s[0]]){
                if(sr.length()>=str.length()){
                    if(sr.substr(0,str.length()) == str){
                        temp.push_back(sr);
                    }
                }
            }
           sort(temp.begin(),temp.end());
         if(temp.empty()){
             temp.push_back("0");
         }
         ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends