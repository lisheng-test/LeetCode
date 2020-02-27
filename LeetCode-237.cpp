/*************************************************************************
	> File Name: LeetCode-237.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 16时43分55秒
 ************************************************************************/

//后面节点的值覆盖前面节点的值，在删除后面的节点
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
    return;
}
