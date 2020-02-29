/*************************************************************************
	> File Name: LeetCode-226.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时46分15秒
 ************************************************************************/

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
