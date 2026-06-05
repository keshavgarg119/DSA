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
    int depth(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh = depth(root->left);
        if(lh==-1) return -1;
        int rh = depth(root->right);
        if(rh==-1) return -1;

        //condition to check balanced tree
        if(abs(lh-rh)>1) {
            return -1;
        }

        return 1 + max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
};