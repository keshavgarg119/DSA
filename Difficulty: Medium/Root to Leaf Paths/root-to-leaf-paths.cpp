/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, vector<int>& path, vector<vector<int>>& result) {
        
        if(root==nullptr) return;
        
        path.push_back(root->data);
        
        if(root->left==nullptr && root->right==nullptr) {
            result.push_back(path);
        }
        
        dfs(root->left, path, result);
        dfs(root->right, path, result);
        
        path.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int>path;
        vector<vector<int>>result;
        
        dfs(root, path, result);
        return result;
    }
};