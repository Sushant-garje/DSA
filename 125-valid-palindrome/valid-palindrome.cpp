#include<cctype>
class Solution {

private:
    bool helper(int i,int j, string& s){
        if(i>=j) return true;
        // skip non-alphanumeric on left
        if (!isalnum(s[i])) return helper(i + 1, j, s);

        // skip non-alphanumeric on right
        if (!isalnum(s[j])) return helper(i, j - 1, s);
        if(tolower(s[i]) != tolower(s[j])) return false;

        return helper(i+1,j-1, s);
    }

public:
    bool isPalindrome(string s) {
        return helper(0,s.size()-1, s);
    }
};