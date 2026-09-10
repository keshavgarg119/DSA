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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int sumOfNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        return root->val + sumOfNodes(root->right) + sumOfNodes(root->left);
    }

    int averageOfSubtree(TreeNode* root) {
        
        if(root == nullptr) {
            return 0;
        }

        int ans = 0;

        int count = countNodes(root);
        int sum = sumOfNodes(root);

        int average = sum / count;

        if(average == root->val) {
            ans++;
        }

        ans += averageOfSubtree(root->left);
        ans += averageOfSubtree(root->right);

        return ans;
    }
};