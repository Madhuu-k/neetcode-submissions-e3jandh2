class Solution {
public:

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true;
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfs(adj, visited, neighbour);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);

        for(auto& e : edges) {

            int u = e[0];
            int v = e[1];

            // reset visited for every edge
            vector<bool> visited(edges.size() + 1, false);

            // check if u already reaches v
            if(!adj[u].empty()) {
                dfs(adj, visited, u);

                if(visited[v]) {
                    return e; // redundant edge
                }
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};