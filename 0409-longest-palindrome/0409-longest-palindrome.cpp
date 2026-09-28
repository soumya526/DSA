class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=1;
            }
            else m[s[i]]++;
        }
        int l=0;
        bool odfound=false;;
        for(auto &it:m){
            if(it.second%2==0){
                l+=it.second;
            }
            else{
                l+=(it.second-1);
                odfound=true;
            }
        }
        if(odfound==true){
            l+=1;
        }
        return l;
    }
};