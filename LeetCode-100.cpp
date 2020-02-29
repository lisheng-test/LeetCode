/*************************************************************************
	> File Name: LeetCode-100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 14时28分26秒
 ************************************************************************/

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
