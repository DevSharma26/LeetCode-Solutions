class Solution {
public:
    vector<int>a;
    int ans = 0, mask = 0;
    
    int maxLength(vector<string>& arr) {
        masking(arr);
        backtrack(0);
        return ans;
    }
    
    void masking(vector<string>&arr){
        for(auto word:arr){
            int x = 0, ok = 1;
            for(auto i:word){
                int shift = i-'a';
                if(x&(1<<shift)) {
                    ok = 0;
                    break;
                }
                x|= (1<<shift);
            }
            if(ok) a.push_back(x);
        }
    }
    
    void backtrack(int id){
        ans = max(__builtin_popcount(mask),ans);
        if(id == a.size()) return;
        
        for(int i = id;i<a.size();i++){
            if((mask & a[i])) continue;
            mask ^= a[i];
            backtrack(i+1);
            mask ^= a[i];
        }
    }
    
};