class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        bool ans ;
        long rev = 0;
        int y = x;

        while(y!=0){
            rev = (rev*10)+(y%10);
            y=y/10;
        }

        if(x==rev) return true;
        else return false;
    }
};