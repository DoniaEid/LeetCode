class Solution {
public:
    int count = 0;

    void solve(int node, int parent, vector<vector<pair<int, int>>>& adj) {
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int isOriginal = edge.second;

            if (neighbor != parent) {
                if (isOriginal == 1) {
                    count++;
                }
                solve(neighbor, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back({c[1], 1}); 
            adj[c[1]].push_back({c[0], 0}); 
        }

        count = 0;
        solve(0, -1, adj);

        return count;
    }
};