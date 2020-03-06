/**
 * Definition for a binary tree node. Funny solution :p !
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Data{
        int val;
        int level;

        bool operator()(Data a, Data b){
            return (a.level < b.level);
        }
    };

    void verticalTraversalUtil(TreeNode *root, map<int, vector<Data> > &mp, int level, int dist){
        if (root == nullptr) return;
        Data data;
        data.val = root->val;
        data.level = dist;
        mp[level].push_back(data);

        verticalTraversalUtil(root->left, mp, level-1,dist+1);
        verticalTraversalUtil(root->right, mp, level+1, dist+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int> > ans;
        map<int, vector<Data> > mp;
        verticalTraversalUtil(root, mp, 0, 0);
        for(auto mpitr : mp){
            sort(mpitr.second.begin(), mpitr.second.end(), Data());
            vector<int> res;
            for (int i = 0; i < mpitr.second.size(); i++){
                res.push_back(mpitr.second[i].val);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
