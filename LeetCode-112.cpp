/*************************************************************************
	> File Name: LeetCode-112.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 18时37分31秒
 ************************************************************************/

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == sum;//出口为叶子节点
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}
