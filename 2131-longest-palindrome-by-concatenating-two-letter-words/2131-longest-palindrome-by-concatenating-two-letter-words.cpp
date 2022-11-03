class Solution {
public:
    int longestPalindrome(vector<string>& w) {
   
    map<string,int> mp;
    int i,n=w.size(),ans=0;
    bool flag=false;
    
    for(i=0;i<n;i++)
        mp[w[i]]++;
    
    for(auto x:mp)
    {
        string s = x.first;
        string t=s;
        reverse(s.begin(),s.end());
        
        if(t==s)
        {
            ans += x.second/2;
            if(x.second%2)
                flag=true;
        }
        else
        {
            if(mp.count(s))
                ans += min(x.second,mp[s]),mp.erase(s);
        }
    }
    ans *= 4;
    
    if(flag)
        ans += 2;
		
    return ans;
    
}
};