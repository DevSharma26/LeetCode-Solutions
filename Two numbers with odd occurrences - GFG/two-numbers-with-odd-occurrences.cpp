//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
     vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        vector<long long int> ans;
        long long int XorTemp =0;
        
        //Firstly we have XOR the whole arr 
        for(long long int x=0; x<N; x++){
            XorTemp = XorTemp^Arr[x];
        }
        
        //Secondly, now we create a BIT_MASK 
        long long int mask = XorTemp & -XorTemp; //StraightUP Formula for masking
        long long int x =0;
        long long int y =0;
        
        //Thirdly we "&" the arr with mask and got our digit which is of odd occurence
        for(long long int num=0; num<N; num++){
            if((Arr[num]&mask) == 0){
                x^=Arr[num];
            }
            
            else{
                y^=Arr[num];
            }
        }
        
        //Finally we have to throw the answer decreasing order 
        if(x>y){
            ans.push_back(x);
            ans.push_back(y);
        }
        else{
            ans.push_back(y);
            ans.push_back(x);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends