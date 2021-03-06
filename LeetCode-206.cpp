/*************************************************************************
	> File Name: LeetCode-206.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 15时31分17秒
 ************************************************************************/
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
