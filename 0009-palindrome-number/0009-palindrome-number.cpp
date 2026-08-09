class Solution {
public:
    bool isPalindrome(int x) {
        long long int n=0,y;
        y=x;
        while(y>0){
            n=n*10;
            int remain=y%10;
            n=n+remain;
            y=y/10;
        }
        if(n==x){
            return true;
        }
        else{
            return false;
        }
    }
};