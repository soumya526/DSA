class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=0;
            }
            else{
                m[s[i]]++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==0){
                return i;
            }
        }
        return -1;
    }
};