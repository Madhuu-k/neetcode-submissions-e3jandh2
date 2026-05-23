class Solution {
public:
    void dfs(int i, vector<bool>& visited, vector<vector<int>>& edges){
        visited[i] = true;
        for(int neighbour : edges[i]){
            if(!visited[neighbour]) dfs(neighbour, visited, edges);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); 
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                components++;
            }
        }

        return components;
    }
};
