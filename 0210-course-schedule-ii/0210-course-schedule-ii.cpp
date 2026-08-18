class Solution {
public:
     bool isCycleDFS(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>&edges){
        vis[src]=true;
        recPath[src]=true;
        for(int v:edges[src]){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,edges)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
            }
        }
            recPath[src]=false;
            return false;
    }
    void topoOrder(int src,vector<bool>&vis,stack<int>& s,vector<vector<int>>&edges){
        vis[src]=true;
        for(int v:edges[src]){
                if(!vis[v]){
                    topoOrder(v,vis,s,edges);
                }
            }
        s.push(src);
    }
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        
        // Build adjacency list: prerequisite b -> course a
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,adj)){
                    return ans;
                }
            }
        }
        stack<int>s;
        vis.assign(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topoOrder(i,vis,s,adj);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};