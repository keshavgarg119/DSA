/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        /*
        queue<Node*>q;

        q.push(root);
        while(!q.empty()) {
            
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();

                if(i < size-1) {
                    node->next = q.front();
                }

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }

            } 
        }

        return root;*/

        Node* levelStart = root;

        while(levelStart->left!=nullptr) {
            Node* curr = levelStart;

            while(curr!=nullptr) {
                curr->left->next = curr->right;

                if(curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            levelStart = levelStart->left;
        }

        return root;
    }
};