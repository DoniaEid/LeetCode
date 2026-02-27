
class Solution {
public:
    int minOperations(std::string s, int k) {
        int n = s.length();
        int initial_zeros = 0;
        for (char c : s) {
            if (c == '0') initial_zeros++;
        }

        if (initial_zeros == 0) return 0;

        std::set<int> unvisited[2];
        for (int i = 0; i <= n; ++i) {
            unvisited[i % 2].insert(i);
        }

        std::queue<std::pair<int, int>> q;
        q.push({initial_zeros, 0});
        unvisited[initial_zeros % 2].erase(initial_zeros);

        while (!q.empty()) {
            int curr_z = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (curr_z == 0) return dist;

            int min_i = std::max(0, k - (n - curr_z));
            int max_i = std::min(k, curr_z);

            // z' = z + k - 2*i
            int min_z_prime = curr_z + k - 2 * max_i;
            int max_z_prime = curr_z + k - 2 * min_i;

            int target_parity = (curr_z + k) % 2;
            auto& s_set = unvisited[target_parity];

            auto it = s_set.lower_bound(min_z_prime);
            std::vector<int> to_erase;
            while (it != s_set.end() && *it <= max_z_prime) {
                q.push({*it, dist + 1});
                to_erase.push_back(*it);
                it++;
            }

            for (int z : to_erase) {
                s_set.erase(z);
            }
        }

        return -1;
    }
};