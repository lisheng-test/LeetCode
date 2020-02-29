/*************************************************************************
	> File Name: LeetCode-257.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 20时39分47秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getPathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}//找路径总数

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buffer) {//
    if (root == NULL) return 0;
    len += sprintf(buffer + len, "%d", root->val);
    buffer[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buffer);
        return 1;
    }//判断是到叶子节点
    len += sprintf(buffer + len, "->"); 
    int cnt = getResult(root->left, len, k, ret, buffer);
    cnt += getResult(root->right, len, k + cnt, ret, buffer);
    return cnt;//因为dfs返回cnt接收的节点个数
}

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}//树的高度

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 10 * getDepth(root);
    char *buffer = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buffer);
    *returnSize = pathCnt;
    return ret;
}
