/*************************************************************************
	> File Name: LeetCode-104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时14分51秒
 ************************************************************************/

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}
