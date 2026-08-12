class Solution {
public:
    void help(vector<int>&nums,vector<int>&g,vector<vector<int>>&ans,int i){
        ans.push_back(g);
        for(int st=i;st<nums.size();st++){
            g.push_back(nums[st]);
            help(nums,g,ans,st+1);
            g.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>g;
        vector<vector<int>>ans;
        help(nums,g,ans,0);
        return ans;
    }
};