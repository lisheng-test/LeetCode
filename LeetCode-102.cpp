/*************************************************************************
	> File Name: LeetCode-102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时00分19秒
 ************************************************************************/

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1; 
}//找到树的深度

void getCnt(struct TreeNode *root, int k, int *cnt) {
    if (root == NULL) return;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);
    getCnt(root->right, k + 1, cnt);
}//找每层树节点的个数

void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if (root == NULL) return;
    ret[k][cnt[k]++] = root->val;//赋值到二维数组
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);
    return ;//将节点的值存在数组里；
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    int *cnt = (int *)calloc(depth, sizeof(int));
    getCnt(root, 0, cnt);
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, 0, cnt, ret);
    *returnSize = depth;//传出参数，因为要改变，用的就是指针变量
    *returnColumnSizes = cnt;//传出参数
    return ret;
}
