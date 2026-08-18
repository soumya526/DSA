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
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // Build adjacency list: prerequisite b -> course a
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};