class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        string ans="";
        vector<string>str1;
        for(int i=0;i<n;i++){
            string h;
            if(path[i]!='/'){
                while(i<n && path[i]!='/'){
                    h+=path[i];
                    i++;
                }
                str1.push_back(h);
                i--;
            }    
        }
        vector<string>str2;
        for(int i=0;i<str1.size();i++){
            if(str1[i]==".") continue;
            else if(str1[i]==".."){
                if (!str2.empty()) {
                    str2.pop_back(); // Pop the parent directory
                }
            }
            else{
                str2.push_back(str1[i]);
            }
        }
        for(int i=0;i<str2.size();i++){
            ans+='/';
            ans+=str2[i];
        }
        return ans.empty()?"/":ans;
    }
};