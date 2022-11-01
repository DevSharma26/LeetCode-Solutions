//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{ 

public:

    int count_greater(vector<int> &vg,int target){  

          //binary search tocount no of elements smaller than                                                           //target or upper_bound in stl c++

        int st=0,end=vg.size()-1;

        while(st<=end){

            int mid=st+(end-st)/2;

            if(vg[mid]<=target){

                st=mid+1;

            }else{

                end=mid-1;

            }

        }return st;

    }

    int median(vector<vector<int>> &matrix, int r, int c){

        int low=0;

        int high=1e9;

        while(low<=high){

            int mid=low+(high-low)/2;

            int cnt=0;

            for(int i=0;i<r;i++){  

              cnt+=count_greater(matrix[i],mid);

            }

            if(cnt<=(r*c)/2){

                low=mid+1;

            }else{

                high=mid-1;

            }

        }return low;

    }

 

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends