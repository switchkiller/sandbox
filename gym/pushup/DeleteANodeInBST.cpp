/** Tree - *****
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int successor(TreeNode* root){
        root = root->right;
        while(root->left){
            root = root->left;
        }
        return root->val;
    }

    int predecessor(TreeNode* root){
        root = root->left;
        while(root->right){
            root = root->right;
        }
        return root->val;
    }

    TreeNode* deleteNodeUtil(TreeNode* root, int key){
        if (!root) return nullptr;

        if (key < root->val){
            root->left = deleteNodeUtil(root->left,key);
        }
        else if (key > root->val){
            root->right = deleteNodeUtil(root->right, key);
        } else{
            if (!root->left && !root->right) root = nullptr;

            else if (root->left){
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            } else {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeUtil(root,key);
    }
};
