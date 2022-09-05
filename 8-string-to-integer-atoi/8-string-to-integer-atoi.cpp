class Solution {
public:
    int myAtoi(string str) {
        int sign =1;
        long int result=0;
        int i;
        int len=str.size();
        for(i=0;i<len;i++) if(str[i]!=' ') break;
        if(str[i]=='+'||str[i]=='-') sign = str[i++] == '-' ? -1 : 1;
        
        while(i<len && isdigit(str[i])){
            result= result*10 + (str[i++]-'0');
            if(result*sign >= INT_MAX) return INT_MAX;
            if(result*sign <= INT_MIN) return INT_MIN;
        } 
        return result*sign;
    }
};