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
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    int ans = 0;

    Info solve(TreeNode* root) {
        if(root==nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if(left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            return {true, currSum, min(root->val, left.minVal), max(root->val, right.maxVal)};
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};