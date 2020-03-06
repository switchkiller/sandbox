/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) return {{}};
        queue<Node*> q;
        q.push(root);
        int sz = 1;
        vector<int> level;

        while(!q.empty()){
            Node *root = q.front();
            q.pop();
            level.push_back(root->val);
            sz--;
            vector<Node*> children = root->children;
            for (auto child : children){
                if (child)
                    q.push(child);
            }
            if (sz == 0){
                sz = q.size();
                res.push_back(level);
                level.clear();
            }
        }

        return res;
    }
};
