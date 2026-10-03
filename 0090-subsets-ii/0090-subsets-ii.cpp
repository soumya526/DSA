class Solution {
public:
     void subsets(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&subset){
        if(i==nums.size()){
            subset.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        subsets(nums,ans,i+1,subset);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx-1]==nums[idx] ){
            idx++;
        }
        subsets(nums,ans,idx,subset);
     }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>subset;
        vector<int>ans;
        subsets(nums,ans,0,subset);
        return subset;
    }
};