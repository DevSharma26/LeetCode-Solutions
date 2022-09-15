class Solution {
public:
vector<int> findOriginalArray(vector<int>& changed) {
  
  sort(changed.begin(), changed.end());
  map<int,int>mp;
  vector<int>ans;
  int size = changed.size();
  int zerocount = 0;
  for(int i = 0;i < changed.size(); i++)
  {
      if(changed[i] == 0)
      {
          zerocount++;
      }
      mp[changed[i]]++;
  }
  if(zerocount%2 == 1)
  {
      return {};
  }
  for(int i = 0;i < zerocount/2; i++)
  {
      ans.push_back(0);
  }
  for(int i = 0;i < size; i++)
  {
      if(changed[i] == 0)
      {
          continue;
      }
      if(mp.find(changed[i]) != mp.end())
      {
          if(mp.find(2*changed[i]) == mp.end())
          {
              return {};
          }else
          {
              mp[changed[i]]--;
              if(mp[changed[i]] == 0)
              {
                  mp.erase(changed[i]);
              }
              ans.push_back(changed[i]);
              mp[2*changed[i]]--;
              if(mp[2*changed[i]] == 0)
              {
                  mp.erase(2*changed[i]);
              }
          }
      }
  }
  return ans;
}
};