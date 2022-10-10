class Solution
{
public:
    std::string breakPalindrome(std::string palindrome)
    {
        int n = palindrome.length();
        if (n < 2) return "";

        int l = 0;

        while (l < n / 2)
        {
            
            if (palindrome[l] > 'a')
            {
                palindrome[l] = 'a';
                return palindrome;
            }
            l++;
        }

      
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};