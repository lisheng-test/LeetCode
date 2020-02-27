/*************************************************************************
	> File Name: LeetCode-234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 16时16分07秒
 ************************************************************************/

int get_len(struct ListNode *node){
    int n = 0;
    while(node) n++, node = node->next;
    return n;
}

struct ListNode *reverser(struct ListNode *head, int n){
    struct ListNode ret, *p = head, *q;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p){
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;//翻转后一半的链表判断是否与前一半是否一致
}

bool isPalindrome(struct ListNode* head){
    int len = get_len(head);
    struct ListNode *p = head, *q = reverser(head, (len + 1) / 2);
    while(q){
        if(p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
