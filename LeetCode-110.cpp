/*************************************************************************
	> File Name: LeetCode-110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时55分15秒
 ************************************************************************/

int Depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = Depth(root->left), r= Depth(root->right);
    return (l > r ? l : r) + 1;
}



bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    int l = Depth(root->left), r = Depth(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
