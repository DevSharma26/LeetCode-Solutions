//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&mat){

     int n = mat.size();

     for(int i = 0;i<n;i++)

     {

         for(int j = 0;j<n;j++)

         {

             for(int k = 0;k<n;k++)

             {

                 if(mat[j][k] == -1)

                 {

                     if(mat[j][i] != -1 && mat[i][k] != -1)

                     mat[j][k] = mat[j][i] + mat[i][k];

                 }

                 else 

                 {

                     if(mat[j][i] != -1 && mat[i][k] != -1)

                     mat[j][k] = min(mat[j][k] , mat[j][i]+mat[i][k]);

                 }

                 

             }

         }

     }

 }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends