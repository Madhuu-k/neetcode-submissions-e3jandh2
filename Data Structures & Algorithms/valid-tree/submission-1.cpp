class Solution {
public:
    bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]) {
                if(dfs(neighbour, node, visited, adj)) return true;
            }
            else if (neighbour != parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int components = 0;
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;
                if(dfs(i, -1, visited, adj)) return false;
            }
        }

        return (components == 1) ? true : false;
    }
};
