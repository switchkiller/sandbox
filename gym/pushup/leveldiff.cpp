// Problem  : https://practice.geeksforgeeks.org/problems/odd-even-level-difference/1

int getLevelDiffUtil(Node *root, int lvl){
    if (root == NULL) return 0;
    int sum;
    sum = getLevelDiffUtil(root->left, lvl+1) + getLevelDiffUtil(root->right, lvl+1);
    sum += (lvl % 2 == 0) ? (root->data) : -(root->data);
    return sum;
}

int getLevelDiff(Node *root)
{
   //Your code here
   return getLevelDiffUtil(root, 0);
}
