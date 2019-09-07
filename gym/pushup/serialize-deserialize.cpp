/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
  // using istringstream and ostringstream methods to make manipulations.
    const char isVal = '\2';
    const char isNull = '\3';
    void serialize_tree(TreeNode *root, ostringstream& out){
        if (root){
            out << isVal;
            out << root->val;
            serialize_tree(root->left, out);
            serialize_tree(root->right, out);
        }
        else out << isNull;
    }

    TreeNode* deserialize_tree(istringstream& in){
        if (in.get() == isVal){
            // do something
            int val;
            in >> val;
            TreeNode *root = new TreeNode(val);
            root->left = deserialize_tree(in);
            root->right = deserialize_tree(in);
            return root;
        }
        return nullptr;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize_tree(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize_tree(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
