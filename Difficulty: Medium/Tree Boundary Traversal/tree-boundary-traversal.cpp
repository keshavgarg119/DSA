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
  
    bool isLeaf(Node* root) {
        if(root->left==nullptr && root->right==nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void addLeft(Node* node, vector<int>&ans) {
        
        node = node->left;
        
        while(node) {
            if(!isLeaf(node)) {
                ans.push_back(node->data);
            }
            
            if(node->left!=nullptr) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        
    }
    
    void addLeaves(Node* node, vector<int>&ans) {
        if(isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }
        
        if(node->left) addLeaves(node->left, ans);
        if(node->right) addLeaves(node->right, ans);
    }
    
    void addRight(Node* node, vector<int>&ans) {
        
        node = node->right;
        vector<int>temp;
        
        while(node) {
            if(!isLeaf(node)) {
                temp.push_back(node->data);
            }
            
            if(node->right != nullptr) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        
        for(int i=temp.size()-1; i>=0; i--) {
            ans.push_back(temp[i]);
        }
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==nullptr) return ans;
        
        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeft(root, ans);
        addLeaves(root, ans);
        addRight(root, ans);
        
        return ans;
    }
};