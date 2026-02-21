class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, bool>>> adj(n);
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, true});
            adj[v].push_back({u, false});
        }

        int count = 0;
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0); 
        visited[0] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& neighbor : adj[curr]) {
                int nextNode = neighbor.first;
                bool isOriginal = neighbor.second;

                if (!visited[nextNode]) {
                    if (isOriginal) {
                        count++;
                    }
                    visited[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }

        return count;
    }
};