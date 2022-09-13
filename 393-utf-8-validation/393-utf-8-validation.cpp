class Solution {
    int countFrontOne(int num){    
        int consecutive_1 = 0;   
        int digit = 0;     
        
        while(num){
            consecutive_1 = (num%2) ? consecutive_1 +1 : 0;
            num /= 2;
            digit++;
        }
        
        if(digit != 8) return 0;
        return consecutive_1;
    }
    
public:
    bool validUtf8(vector<int>& data) {
        int remain = 0;     
        int count = 0;      
        
        for(auto& d: data){
            count = countFrontOne(d);
            if(remain>0 && count != 1){
                return false;
            }
            if(remain<=0 && count == 1){
                return false;
            }
            if(count > 4)
                return false;
            
            if(count != 1) remain = count;
            remain--;
        }
        
        if(remain == -1 || remain == 0) return true;
        return false;
    }
};