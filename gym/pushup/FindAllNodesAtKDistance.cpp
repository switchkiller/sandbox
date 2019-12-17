/**
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
    void findAtDistanceKUtil(TreeNode *root, int dist, TreeNode *prev, vector<int> &ans){
        if (dist < 0 || root == nullptr) return;
        if (dist == 0){
            ans.push_back(root->val);
            return;
        }
        if (root->left != nullptr && root->left != prev){
            findAtDistanceKUtil(root->left,dist-1,root->left, ans);
        }
        if (root->right != nullptr && root->right != prev){
            findAtDistanceKUtil(root->right, dist-1, root->right,ans);
        }
    }

    void findAtDistanceK(TreeNode *root, TreeNode *target, vector<int> &ans, stack<TreeNode *> &st, int dist){
        if (root == nullptr) return;

        if (root == target){
            findAtDistanceKUtil(root,dist,target, ans);
            TreeNode *prev = target;
            int i = 1;
            while(!st.empty()){
                TreeNode *curr = st.top();
                findAtDistanceKUtil(curr,dist-i,prev,ans);
                prev = curr;
                st.pop();
                i++;
            }
            return;
        }
        else {
            st.push(root);
            findAtDistanceK(root->left, target, ans, st, dist);
            findAtDistanceK(root->right, target, ans, st, dist);
            if (!st.empty())
                st.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root == nullptr) return {};

        vector<int> ans;
        stack<TreeNode *> st;
        findAtDistanceK(root, target, ans, st, K);
        return ans;
    }
};
