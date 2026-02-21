class Solution {
public:
    int count = 0;
    vector<bool> visited;

    void dfs(int u, vector<vector<int>>& adj_out, vector<vector<int>>& adj_in) {
        visited[u] = true;

        for (int v : adj_out[u]) {
            if (!visited[v]) {
                count++; 
                dfs(v, adj_out, adj_in);
            }
        }

        for (int v : adj_in[u]) {
            if (!visited[v]) {
                dfs(v, adj_out, adj_in);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj_out(n);
        vector<vector<int>> adj_in(n); 
        
        for (auto& c : connections) {
            adj_out[c[0]].push_back(c[1]);
            adj_in[c[1]].push_back(c[0]);
        }

        visited.assign(n, false);
        count = 0;
        dfs(0, adj_out, adj_in);
        
        return count;
    }
};