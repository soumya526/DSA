class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+tasks[i];
        }
        long long total_task_time=prefix[n];
        long long completed_work=0;
        vector<int>ans;
        ans.reserve(shifts.size());
        for(int shift:shifts){
            completed_work+=shift;

            if(completed_work>=total_task_time){
                ans.push_back(0);
                completed_work=0;
            }
            else{
                auto it=upper_bound(prefix.begin(),prefix.end(),completed_work);
                int fully_completed=(it-prefix.begin())-1;
                ans.push_back(n-fully_completed);
            }
        }
        return ans;
    }
};