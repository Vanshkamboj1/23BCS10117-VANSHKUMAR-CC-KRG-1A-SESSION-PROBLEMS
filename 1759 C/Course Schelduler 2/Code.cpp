class Solution {
public:
    void dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &vis,stack<int> &st,vector<bool> &dfsv,bool &c){
        vis[node] = true;
        dfsv[node]=true;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,st,dfsv,c);
            }else{
                if(dfsv[i]==true){
                    c  = true;
                }
            }
        }
        st.push(node);
        dfsv[node]=false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> dfsv(numCourses,false);
        stack<int> st;
        bool c=false;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st,dfsv,c);
            }
        }
        
        vector<int> ans;
        if(c){
            return ans;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};