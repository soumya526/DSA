class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        int n=ransomNote.size();
        int k=magazine.size();
        for(int i=0;i<n;i++){
            if(m.find(magazine[i])==m.end()){
                    m[magazine[i]]=0;
            }
            else{
                m[magazine[i]]++;
            }
        }
        for(char c:magazine){
            m[c]++;
        }
        for(char c:ransomNote){
            if(m[c]==0){
                return false;
            }
            m[c]--;
        }
        return true;
    }
};