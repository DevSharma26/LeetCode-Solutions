//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      int longestPerfectPiece(int arr[], int N) {

        int res = 1;

        int last = 0;

        int max = arr[0] , min = arr[0];

        int i = 1;

        int y = 0;

        int mi =0 , si = 0;

        while(i<N){

            if(arr[i] >= max){

                max = arr[i];

                mi = i;

            }

            if(arr[i] <= min){

                min = arr[i];

                si = i;

            }

            if(max - min <=1){

                y = i - last + 1;

                i++;

                if(y>res){

                    res = y;

                }

            }

            else{

               if(arr[i] == max){

                   si++;

                   min = arr[i];

                   last = si;

               }

               else{

                   mi++;

                   max = arr[i];

                   last = mi;

               }

            }

        }

        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends