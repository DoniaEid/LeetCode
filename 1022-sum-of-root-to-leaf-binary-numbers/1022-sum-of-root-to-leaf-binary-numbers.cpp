class Solution {
public:
    int totalSum = 0;
    vector<int> path; 

    void calculateBinary() {
        int res = 0;
        for (int bit : path) {
            res = (res << 1) | bit;
        }
        totalSum += res;
    }

    void dfs(TreeNode* s) {
        if (!s) return;

        path.push_back(s->val);

        if (!s->left && !s->right) {
            calculateBinary();
        }

        if (s->left) dfs(s->left);
        if (s->right) dfs(s->right);

        path.pop_back(); 
    }

    int sumRootToLeaf(TreeNode* root) {
        totalSum = 0;
        path.clear();
        dfs(root);
        return totalSum;
    }
};