class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l=s.size();
        string a="";
        for(int i=0;i<l/2;i++){
            a+=s[i];
            int n=a.size();
            if(l%n==0){
                string constructed="";
                int times=l/n;
                for(int j=0;j<times;j++){
                    constructed+=a;
                }
                if(constructed==s)return true;
            }
        }
        return false;
    }
};