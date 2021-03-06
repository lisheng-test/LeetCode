/*************************************************************************
	> File Name: LeetCode-111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时26分55秒
 ************************************************************************/

int minDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL || root->right == NULL) {
        return minDepth(root->left ? root->left : root->right) + 1;
    }
    return fmin(minDepth(root->left), minDepth(root->right)) + 1; //fmin在<math.h>里
}
