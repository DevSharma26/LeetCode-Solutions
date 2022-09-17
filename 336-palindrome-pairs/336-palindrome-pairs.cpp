class Solution {
public:
    
    bool ispalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if (s[i]!=s[j])
                return false;
            i++;
           j--; 
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
 // a palindrome consists of 3 parts-> left,mid,right ; WHERE LEFT IS REVERSE OF RIGHT [IN PALINDROMES]    
 // there can be two possibilties ->
 //   currentstring = left+mid , so we find the right part  
 // currentstring =mid+rightpart , so we find if any string is equal to reverse of rightpart (so we can append it before currentstring)
 
        unordered_map<string,int> index;
        unordered_map<string,int> revindex;
        unordered_set<string>fullyused;
        int ind=-1;
        for (int i=0;i<words.size();i++)
        {
            
            index[words[i]]=i;
            string s=words[i];
            
            if (s=="")
                ind=i;
            
            reverse(s.begin(),s.end());
            
            revindex[s]=i;
        }
        vector<vector<int>> result;
        for (int i=0;i<words.size();i++)
        {
            string s=words[i]; // now currentword contains left part+middlepart of palindrome or right part+middlepart of palindrome 
            if (s=="")
                continue;
            bool ispalin=ispalindrome(s,0,s.size()-1);
            if (ind!=-1 && ispalin)
            {
                result.push_back({ind,i});
                result.push_back({i,ind});
            }
            
            string temp="";
            for (int j=0;j<s.size()-1;j++)
            {
                temp.push_back(s[j]);
                if (revindex.find(temp)!=revindex.end())
                {
                    if (ispalindrome(s,j+1,s.size()-1))
                    {
                         result.push_back({i,revindex[temp]});
                    }
                }
            }
            temp.push_back(s.back()); // last character inserted
            if (revindex.find(temp)!=revindex.end() && fullyused.find(temp)==fullyused.end() && revindex[temp]!=i)
                        {
                            int tempindex=revindex[temp];
                           fullyused.insert(words[tempindex]); // fully used means if whole string is taken -> we have considered it in both possibilities, it comes first and then at 2nd position
                
                           fullyused.insert(temp);
                            result.push_back({i,tempindex});
                            result.push_back({tempindex,i}); 
                        }
       ///////////////////////
            temp="";
            for (int j=s.size()-1;j>=1;j--)
            {
                temp.push_back(s[j]);
                if (index.find(temp)!=index.end())
                {
                    if (ispalindrome(s,0,j-1))
                    {
                         result.push_back({index[temp],i});
                    }
                }
            }
            temp.push_back(s[0]); //now temp==reverse(s)
             if (index.find(temp)!=index.end() && fullyused.find(temp)==fullyused.end() && index[temp]!=i)
                        {
                           int tempindex=index[temp];
                           fullyused.insert(words[tempindex]);
                            result.push_back({i,tempindex});
                            result.push_back({tempindex,i}); 
                        }              

        }
        
        return result;
    }
};