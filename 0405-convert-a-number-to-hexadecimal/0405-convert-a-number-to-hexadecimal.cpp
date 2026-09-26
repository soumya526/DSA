class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        unsigned int n=num;
        string hex="0123456789abcdef";
        string ans="";
        while(n!=0){
            int digit=n & 15;
            ans+=hex[digit];
            n=n>>4;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};