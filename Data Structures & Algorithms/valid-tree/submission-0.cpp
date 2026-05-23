class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int parent){
        visited[node] = true;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(dfs(adj, visited, neighbour, node)) return true;
            }
            else if(neighbour != parent) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        int components = 0;
        vector<bool> visited(n, false);

        vector<vector<int>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                components++;

                if(dfs(adj, visited, i, -1)) return false;
            }
        }

        return (components == 1) ? true : false;

    }
};
