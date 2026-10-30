class Solution {
public:
    bool isPalindrome(string s) {
       int start = 0;
       int end = s.length() - 1;
       while (start < end){
        while (start < end && !alphaNum(s[start])){
            //if start is pointing to not a character, increment
            start++;
        }
        while (start < end && !alphaNum(s[end])){
            //if end is pointing to not a character, decrement
            end--;
        }
        if(tolower(s[start]) != tolower(s[end])) {
            //convert to lowercase then compare
            return false;
        }
        start++;
        end--;
       }
       return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || 
        c >= '0' && c <= '9');
    }
};
