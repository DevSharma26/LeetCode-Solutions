class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>s;
        for(auto x:sentence){
            s.insert(x);
        }
        if(s.size()==26)
            return true;
        else return false;
    }
};