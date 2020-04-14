/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * TC - 32/55 passed.. modulo operation has some mistake :o
 */

class Solution {
private:
    long long ans;
    int MODULO;
public:
    long long getSum(TreeNode *root){
        if (root == nullptr){
            return 0;
        }
        return root->val + getSum(root->left) + getSum(root->right);
    }

    void getMaxProductUtil(TreeNode *root, int sum){
        if (root == nullptr){
            return;
        }
        long long s = getSum(root);
        long long temp = ((s % MODULO) * ((sum-s) % MODULO)) % MODULO;
        ans = (ans < temp) ? temp : ans;
        // ans = max(ans,s*(sum-s));
        getMaxProductUtil(root->left,sum);
        getMaxProductUtil(root->right,sum);
    }

    int maxProduct(TreeNode* root) {
        ans = 0;
        MODULO = 1e9+7;
        int sum = getSum(root);
        // cout << sum;
        getMaxProductUtil(root->left,sum);
        getMaxProductUtil(root->right,sum);
        return (ans%MODULO);
    }
};
