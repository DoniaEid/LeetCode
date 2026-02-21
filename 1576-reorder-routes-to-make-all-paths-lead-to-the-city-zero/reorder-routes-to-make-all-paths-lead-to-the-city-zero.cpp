class Solution {
public:
    int count = 0;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& neighbor : adj[node]) {
            int child = neighbor.first;
            int sign = neighbor.second;

            if (child != parent) {
                count += sign;
                dfs(child, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        count = 0; 

        for (auto& edge : connections) {
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }

        dfs(0, -1, adj);
        
        return count;
    }
};