//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
void getNums(vector<int>& nums,int currNum,int currCount){
        nums.push_back(currNum);
        if(currCount == 7) return;
        int lastDigit = currNum%10;
        if(lastDigit == 0)
            getNums(nums,currNum*10 + 1, currCount+1);
        else if(lastDigit == 9)
            getNums(nums,currNum*10 + 8, currCount+1);
        else{
            getNums(nums,currNum*10 + lastDigit-1, currCount+1);
            getNums(nums,currNum*10 + lastDigit+1, currCount+1);
        }
    }
    int steppingNumbers(int n, int m){
        int currNum = 0;
        vector<int> nums = {0};
        for(int i = 1; i<=9; i++) getNums(nums,i,1);
        sort(nums.begin(), nums.end());
        int index1 = lower_bound(nums.begin(),nums.end(),n) - nums.begin();
        int index2 = upper_bound(nums.begin(),nums.end(),m) - nums.begin()-1;
        return index2-index1+1;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends