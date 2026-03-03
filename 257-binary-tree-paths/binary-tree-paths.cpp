/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;

        // Add current node to path
        if (path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // If leaf node, add to result
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        // Recur left and right
        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};